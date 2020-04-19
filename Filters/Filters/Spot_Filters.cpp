#include "Spot_Filters.h"
#include "Clamp.h"
#include <qimage.h>
#include <qcolor.h>
#include <math.h>


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
	float k = 50;
	img_color.setRgb(clamp<int>(intensity + 2 * k, 255, 0), 
		clamp<int>(intensity + 0.5 * k, 255, 0),
		clamp<int>(intensity - 1 * k, 255, 0));

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
	float k = 50;
	img_color.setRgb(clamp<int>( img_color.red() + k, 255, 0),
		clamp<int>(img_color.green() + k, 255, 0),
		clamp<int>(img_color.blue() + k, 255, 0));

	return img_color;
};

QImage WaveFilter_01::calculateNewImagePixMap(const QImage& img, int radius)
{
	QImage img_result(img);

	for (int x = 0; x < img.width(); x++)
		for (int y = 0; y < img.height(); y++)
		{
			if (((x + 20 * sin(2 * 3.14 * y / 60)) < img.width()) && ((x + 20 * sin(2 * 3.14 * y / 60)) >= 0))
			{
				QColor img_color = img.pixelColor((x + 20 * sin(2 * 3.14 * y / 60)), y);
				img_result.setPixelColor(x, y, img_color);
			}
			else
			{
				QColor img_color = img.pixelColor(x, y);
				img_result.setPixelColor(x, y, img_color);
			}

		}

	return img_result;
};

QImage WaveFilter_02::calculateNewImagePixMap(const QImage& img, int radius)
{
	QImage img_result(img);

	for (int x = 0; x < img.width(); x++)
		for (int y = 0; y < img.height(); y++)
		{
			if (((x + 20 * sin(2 * 3.14 * x / 30)) < img.width()) && ((x + 20 * sin(2 * 3.14 * x / 30)) >= 0))
			{
				QColor img_color = img.pixelColor((x + 20 * sin(2 * 3.14 * x / 30)), y);
				img_result.setPixelColor(x, y, img_color);
			}
			else
			{
				QColor img_color = img.pixelColor(x, y);
				img_result.setPixelColor(x, y, img_color);
			}

		}

	return img_result;
};

QImage MedianFilter::calculateNewImagePixMap(const QImage& img, int radius)
{
	QImage img_result(img);
	int size = radius * 2 + 1;

	for (int x = 0; x < img.width(); x++)
	{
		for (int y = 0; y < img.height(); y++)
		{
			int returnR = 0;
			int returnG = 0;
			int returnB = 0;


		}
	}
};
