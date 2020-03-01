#include "Filters.h"
#include <qimage.h>
#include <qcolor.h>

template<class T>
T clamp(T v, int max, int min)
{
	if (v > max)
		return max;
	else if (v < min)
		return min;

	return v;
}

QImage Invert_filter::calculateNewImagePixMap(const QImage& img, int radius)
{
	QImage img_result(img);

	for(int x = 0; x < img.width(); x++)
		for (int y = 0; y < img.height(); y++)
		{
			QColor img_color = img.pixelColor(x, y);
			img_color.setRgb(255 - img_color.red(), 
				255 - img_color.green(),
				255 - img_color.blue());
			img_result.setPixelColor(x, y, img_color);
		}

	return img_result;
}

QColor Matrix_filter::calculateNewPixelColor(QImage img, int x, int y, int radius)
{
	int returnR = 0;
	int returnG = 0;
	int returnB = 0;
	int size = 2 * radius + 1; //Вычисление диаметра

	for(int i = -radius; i <= radius; i++)
		for (int j = -radius; j <= radius; j++)
		{
			int idx = (i + radius) * size + j + radius;

			QColor color = img.pixelColor(clamp<int>(x + j, img.width() - 1, 0),
				clamp<int>(y + i, img.height() - 1, 0));

			returnR += color.red() * vector[idx];
			returnG += color.green() * vector[idx];
			returnB += color.blue() * vector[idx];
		}

	return QColor(clamp<int>(returnR, 255, 0),
		clamp<int>(returnG, 255, 0),
		clamp<int>(returnB, 255, 0));
}

QImage Matrix_filter::calculateNewImagePixMap(const QImage& img, int radius)
{
	QImage img_result(img);

	for (int x = 0; x < img.width(); x++)
		for (int y = 0; y < img.height(); y++)
		{
			QColor img_color = calculateNewPixelColor(img, x, y, radius);
			img_result.setPixelColor(x, y, img_color);
		}

	return img_result;
};

void Gaussian_blur_filter::createGaussinVector(int radius, int sigma)
{
	//Определяем размер ядра
	const unsigned int size = 2 * radius + 1;
	//коэффициент нормировки ядра
	float norm = 0;
	//Создание ядра фильтра
	vector = new float[size * size];

	//Рассчитываем ядро линейного фильтра
	for(int i = -radius; i <= radius; i++)
		for (int j = -radius; j <= radius; j++)
		{
			int idx = (i + radius) * size + (j + radius);
			vector[idx] = exp(-(i * i + j * j) / (sigma * sigma));
			norm += vector[idx];
		}

	//Нормируем ядро
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			vector[i * size + j] /= norm;
};

QColor GrayScaleFilter::calculateNewPixelColor(QImage img, int x, int y, int radius)
{
	QColor img_color = img.pixelColor(x, y);
	float intensity = (float)(0.36 * img_color.red() + 0.53 * img_color.green() + 0.11 * img_color.blue());
	img_color.setRgb(intensity, intensity, intensity);

	return img_color;
}

QImage GrayScaleFilter::calculateNewImagePixMap(const QImage& img, int radius)
{
	QImage img_result(img);

	for (int x = 0; x < img.width(); x++)
		for (int y = 0; y < img.height(); y++)
		{
			QColor img_color = calculateNewPixelColor(img, x, y, radius);
			img_result.setPixelColor(x, y, img_color);
		}

	return img_result;
};

QImage SepiaFilter::calculateNewImagePixMap(const QImage& img, int radius)
{
	QImage img_result(img);

	for (int x = 0; x < img.width(); x++)
		for (int y = 0; y < img.height(); y++)
		{
			QColor img_color = calculateNewPixelColor(img, x, y, radius);
			img_result.setPixelColor(x, y, img_color);
		}

	return img_result;
};

QColor SepiaFilter::calculateNewPixelColor(QImage img, int x, int y, int radius)
{
	QColor img_color = img.pixelColor(x, y);
	float intensity = (int)(0.36 * img_color.red() + 0.53 * img_color.green() + 0.11 * img_color.blue());
	float k = 5;
	img_color.setRgb(clamp<int>(intensity + 2 * k, img.width() - 1, 0), 
		clamp<int>(intensity + 0.5 * k, img.width() - 1, 0),
		clamp<int>(intensity - 1 * k, img.width() - 1, 0));

	return img_color;
};

QImage BrightnessFilter::calculateNewImagePixMap(const QImage& img, int radius)
{
	QImage img_result(img);

	for (int x = 0; x < img.width(); x++)
		for (int y = 0; y < img.height(); y++)
		{
			QColor img_color = calculateNewPixelColor(img, x, y, radius);
			img_result.setPixelColor(x, y, img_color);
		}

	return img_result;
};

QColor BrightnessFilter::calculateNewPixelColor(QImage img, int x, int y, int radius)
{
	QColor img_color = img.pixelColor(x, y);
	float k = 5;
	img_color.setRgb(clamp<int>( img_color.red() + k, img.width() - 1, 0),
		clamp<int>(img_color.green() + k, img.width() - 1, 0),
		clamp<int>(img_color.blue() + k, img.width() - 1, 0));

	return img_color;
};