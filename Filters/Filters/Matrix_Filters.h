#ifndef _MATRIX_FILTERS_H_
#define _MATRIX_FILTERS_H_
#include <qimage.h>
#include "Spot_Filters.h"
#include <iostream>
using namespace std;

class Matrix_filter : public Filters
{
public:
	float* vector = NULL;
	int mRadius;

	Matrix_filter(int radius = 1) : mRadius(radius) {};
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
	~Blur_filter() {
		delete[] vector;
		mRadius = 0;
	};
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

#endif
