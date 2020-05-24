#version 430

/*****IN, OUT, UNIFORM VARIABLES*****/

in vec3 interpolated_vertex;
out vec4 FragColor;

#define BIG 1000000.0

/*****DATA STRUCTURES*****/

struct Camera
{
   vec3 position;
   vec3 view;
   vec3 up;
   vec3 side;
};

struct Ray
{
   vec3 origin;
   vec3 direction;
};

struct Sphere
{
   vec3 Centre;
   float Radius;
   vec3 Color;
};

struct Material
{
   float ambient;
   float diffuse;
   float specular;
   float specular_power;
};

struct Intersection
{
   float time;
   vec3 point;
   vec3 normal;
   vec3 color;
};

/*****SCENE*****/

Material material = { 0.4, 0.9, 0.0, 512.0 };
vec3 pos_light = vec3(-4, 0, -8);

uniform Camera camera;
//Отношение сторон выходного изображения
uniform vec2 scale;
uniform Sphere spheres[2];

/*****FUNCTIONS*****/

bool IntersectSphere(Sphere sphere, Ray ray, float start, float final, out float time)
{
   ray.origin -= sphere.Centre;
   float A = dot(ray.direction, ray.direction);
   float B = dot(ray.direction, ray.origin);
   float C = dot(ray.origin, ray.origin) - sphere.Radius * sphere.Radius;
   float D = B * B - A * C;
   
   if( D > 0.0)
   {
     D = sqrt(D);
     
     float t1 = (- B - D) / A;
     float t2 = (- B + D) / A;
     
     if(t1 < 0 && t2 < 0)
       return false;
     
     float min_t = min(t1, t2);
     float max_t = max(t1, t2);
     
     if(min_t < 0)
     {
       time = max_t;
       return true;
     }
     
     time = min_t;
     return true;
   }
   return false;
}

bool Intersect(Ray ray, float start, float final, inout Intersection intersect)
{
   bool result = false;
   float time = start;
   intersect.time = final;
   
   for(int i = 0; i < 2; i++)
   {
     Sphere sphere = spheres[i];
     if(IntersectSphere(spheres[i], ray, start, final, time) &&  time < intersect.time)
     {
        intersect.time = time;
        intersect.point = ray.origin + ray.direction * time;
        intersect.normal = normalize(intersect.point - spheres[i].Centre);
        intersect.color = spheres[i].Color;
        result = true;
     }
   }
   return result;
}

vec3 Phong(Intersection intersect, float shadow)
{
   vec3 light = normalize(pos_light - intersect.point);
   float diffuse = max(dot(light, intersect.normal), 0.0);
   vec3 view = normalize(camera.position - intersect.point);
   vec3 reflected = reflect(view, -intersect.normal);
   float specular = pow(max(dot(reflected, light), 0.0), material.specular_power);
   
   return material.ambient * intersect.color + shadow * 
   (material.diffuse * diffuse * intersect.color + material.specular * specular * vec3(1, 1, 1));
}


float Shadow(vec3 point)
{
   float light = 1.0;
   
   vec3 direction = normalize(pos_light - point);
   Ray shadow_ray = Ray(point + direction * 0.001, direction);
   
   Intersection intersect;
   intersect.time = distance(pos_light, point);
   
   if(Intersect(shadow_ray, 0, intersect.time, intersect))
   {
      light = 0.0;
   }
   return light;
}

vec4 Raytrace(Ray primary_ray)
{
   vec4 resultColor = vec4(0, 0, 0, 0);
   Ray ray = primary_ray;
   
   Intersection intersect;
   intersect.time = BIG;
   float start = 0;
   float final = BIG;
   
   if(Intersect(ray, start, final, intersect))
   {
      float shadowing = Shadow(intersect.point);
      resultColor += vec4(Phong(intersect, shadowing), 0.0);
   }
   return resultColor;
}

Ray GenerateRay(Camera camera)
{
   vec2 coords = interpolated_vertex.xy * normalize(scale);
   vec3 direction = camera.view + camera.side * coords.x + camera.up * coords.y;
   
   return Ray(camera.position, normalize(direction));
}

void main(void)
{     
   Ray ray = GenerateRay(camera);
   //FragColor = vec4(abs(ray.direction.xy), 0, 1.0);
   FragColor = Raytrace(ray);
}