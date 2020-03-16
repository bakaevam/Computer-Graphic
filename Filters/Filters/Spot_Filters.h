#ifndef _SPOT_FILTERS_H_
#define _SPOT_FILTERS_H_
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