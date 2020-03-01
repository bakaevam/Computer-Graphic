#ifndef FILTERS_H_
#define FILTERS_H_
#include <qimage.h>

class Filters
{
public:
	Filters() {};
	~Filters() {};

	virtual QImage calculateNewImagePixMap(const QImage& img, int radius) = 0;
};

class Invert_filter: public Filters
{
public:
	Invert_filter() {};
	~Invert_filter() {};

	QImage calculateNewImagePixMap(const QImage& img, int radius);
};

class Matrix_filter : public Filters
{
public:
	float* vector;
	int mRadius;

	Matrix_filter(int radius = 1) : mRadius(radius) {};
	~Matrix_filter() {};
	QImage calculateNewImagePixMap(const QImage& img, int radius);
	QColor calculateNewPixelColor(QImage img, int x, int y, int radius);
};

class Blur_filter : public Matrix_filter
{
public:
	Blur_filter() 
	{
		int size = 2 * mRadius + 1; //Вычисление диаметра
		vector = new float[size * size];
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				vector[i * size + j] = 1.0f / (size * size);
	};
	~Blur_filter() {};
};

class Gaussian_blur_filter : public Matrix_filter
{
public:
	Gaussian_blur_filter() 
	{
		createGaussinVector(3, 2);
	};
	~Gaussian_blur_filter() {};

	void createGaussinVector(int radius, int sigma);
};

class GrayScaleFilter : public Filters
{
public:
	GrayScaleFilter() {};
	~GrayScaleFilter() {};

	QImage calculateNewImagePixMap(const QImage& img, int radius);
	QColor calculateNewPixelColor(QImage img, int x, int y, int radius);
};

class SepiaFilter : public Filters
{
public:
	SepiaFilter() {};
	~SepiaFilter() {};

	QImage calculateNewImagePixMap(const QImage& img, int radius);
	QColor calculateNewPixelColor(QImage img, int x, int y, int radius);
};

class BrightnessFilter : public Filters
{
public:
	BrightnessFilter() {};
	~BrightnessFilter() {};

	QImage calculateNewImagePixMap(const QImage& img, int radius);
	QColor calculateNewPixelColor(QImage img, int x, int y, int radius);
};
#endif