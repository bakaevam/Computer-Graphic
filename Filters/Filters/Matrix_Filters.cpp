#include "Matrix_Filters.h"
#include "Clamp.h"
#include <qimage.h>
#include <qcolor.h>

QColor Matrix_filter::calculateNewPixelColor(QImage img, int x, int y, int radius)
{
	float returnR = 0;
	float returnG = 0;
	float returnB = 0;
	int size = 2 * radius + 1; //Вычисление диаметра

	for (int i = -radius; i <= radius; i++)
		for (int j = -radius; j <= radius; j++)
		{
			int idx = (i + radius) * size + j + radius;

			QColor color = img.pixelColor(clamp<int>(x + i, img.width() - 1, 0),
				clamp<int>(y + j, img.height() - 1, 0));

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
	for (int i = -radius; i <= radius; i++)
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

QImage Embossing_filter::calculateNewImagePixMap(const QImage& img, int radius, int coef, bool norm)
{
	QImage img_result(img);

	for (int x = 0; x < img.width(); x++)
		for (int y = 0; y < img.height(); y++)
		{
			QColor img_color = calculateNewPixelColor(img, x, y, radius, coef, norm);
			img_result.setPixelColor(x, y, img_color);
		}

	return img_result;
};

QColor Embossing_filter::calculateNewPixelColor(QImage img, int x, int y, int radius, int coef, bool norm)
{
	float returnR = 0;
	float returnG = 0;
	float returnB = 0;
	int size = 2 * radius + 1; //Вычисление диаметра

	float coefNorm = 0;
	for (int i = -radius; i <= radius; i++)
		for (int j = -radius; j <= radius; j++)
		{
			int idx = (i + radius) * size + j + radius;

			QColor color = img.pixelColor(clamp<int>(x + i, img.width() - 1, 0),
				clamp<int>(y + j, img.height() - 1, 0));

			returnR += color.red() * vector[idx] * 2 + coef;
			returnG += color.green() * vector[idx] * 2 + coef;
			returnB += color.blue() * vector[idx] * 2 + coef;

			coefNorm++;
		}

	returnR /= coefNorm;
	returnG /= coefNorm;
	returnB /= coefNorm;

	return QColor(clamp<int>(returnR, 255, 0),
		clamp<int>(returnG, 255, 0),
		clamp<int>(returnB, 255, 0));
};