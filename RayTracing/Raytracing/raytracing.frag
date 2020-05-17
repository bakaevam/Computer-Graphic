#version 430

in vec3 interpolated_vertex;
out vec4 FragColor;

void main(void)
{
   FragColor = vec4(abs(interpolated_vertex.xy), 0, 1.0);
}