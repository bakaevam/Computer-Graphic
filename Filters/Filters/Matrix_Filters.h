#ifndef _MATRIX_FILTERS_H_
#define _MATRIX_FILTERS_H_
#include <qimage.h>
#include "Spot_Filters.h"
#include <iostream>
using namespace std;

#define MATRIX_SIZE 3

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

class Sobel_filter_OX : public Matrix_filter
{
public:
	Sobel_filter_OX()
	{
		int size = 2 * mRadius + 1;
		vector = new float[size * size];

		vector[0] = -1;
		vector[1] = 0;
		vector[2] = 1;
		vector[3] = -2;
		vector[4] = 0;
		vector[5] = 2;
		vector[6] = -1;
		vector[7] = 0;
		vector[8] = 1;
	}
	~Sobel_filter_OX()
	{
		delete[] vector;
		mRadius = 0;
	}
};

class Sobel_filter_OY : public Matrix_filter
{
public:
	Sobel_filter_OY()
	{
		int size = 2 * mRadius + 1;
		vector = new float[size * size];

		vector[0] = -1;
		vector[1] = 2;
		vector[2] = -1;
		vector[3] = 0;
		vector[4] = 0;
		vector[5] = 0;
		vector[6] = 1;
		vector[7] = 2;
		vector[8] = 1;
	}
	~Sobel_filter_OY()
	{
		delete[] vector;
		mRadius = 0;
	}
};

class Sharpness_filter_01 : public Matrix_filter
{
public:
	Sharpness_filter_01()
	{
		int size = 2 * mRadius + 1;
		vector = new float[size * size];

		vector[0] = 0;
		vector[1] = -1;
		vector[2] = 0;
		vector[3] = -1;
		vector[4] = 5;
		vector[5] = -1;
		vector[6] = 0;
		vector[7] = -1;
		vector[8] = 0;
	};
	~Sharpness_filter_01()
	{
		delete[] vector;
		mRadius = 0;
	}
};

class Sharpness_filter_02 : public Matrix_filter
{
public:
	Sharpness_filter_02()
	{
		int size = 2 * mRadius + 1;
		vector = new float[size * size];

		vector[0] = -1;
		vector[1] = -1;
		vector[2] = -1;
		vector[3] = -1;
		vector[4] = 9;
		vector[5] = -1;
		vector[6] = -1;
		vector[7] = -1;
		vector[8] = -1;
	};
	~Sharpness_filter_02()
	{
		delete[] vector;
		mRadius = 0;
	}
};

class Embossing_filter : public Matrix_filter
{
public:
	Embossing_filter()
	{
		int size = 2 * mRadius + 1;
		vector = new float[size * size];

		vector[0] = 1;
		vector[1] = 1;
		vector[2] = 0;
		vector[3] = 1;
		vector[4] = 0;
		vector[5] = -1;
		vector[6] = 0;
		vector[7] = -1;
		vector[8] = -1;
	}
	~Embossing_filter()
	{
		delete[] vector;
		mRadius = 0;
	}

	QImage calculateNewImagePixMap(const QImage& img, int radius, int correction, bool norm);
	QColor calculateNewPixelColor(QImage img, int x, int y, int radius, int correction, bool norm);
};

#endif
