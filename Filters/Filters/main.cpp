#include <QtCore/QCoreApplication>
#include <qimage.h>
#include <string.h>
#include <iostream>
#include "Filters.h"
using namespace std;

int main(int argc, char *argv[])
{
	string s;
	QImage img;

	//Обход по массиву переданных элементов 
	//Сохранение адреса изображения
	for (int i = 0; i < argc; i++)
		if (!strcmp(argv[i], "-p") && (i + 1 < argc))
			s = argv[i + 1];

	img.load(QString(s.c_str()));

	QImage newImg(img);
	Invert_filter* invert = new Invert_filter();
	newImg = invert->calculateNewImagePixMap(img, 0);

	QImage newImgBlur(img);
	Blur_filter* blur = new Blur_filter();
	newImgBlur = blur->calculateNewImagePixMap(img, 0);

	QImage newImgGausBlur(img);
	Gaussian_blur_filter* Gausblur = new Gaussian_blur_filter();
	newImgGausBlur = Gausblur->calculateNewImagePixMap(img, 0);

	QImage newImgGray(img);
	GrayScaleFilter* gray = new GrayScaleFilter();
	newImgGray = gray->calculateNewImagePixMap(img, 0);

	QImage newImgSepia(img);
	SepiaFilter* sepia = new SepiaFilter();
	newImgSepia = sepia->calculateNewImagePixMap(img, 0);

	QImage newImgBright(img);
	BrightnessFilter* bright = new BrightnessFilter();
	newImgBright = bright->calculateNewImagePixMap(img, 0);

	newImg.save("pictures\\Invert.png");
	newImgBlur.save("pictures\\Blur.png");
	newImgGausBlur.save("pictures\\GausBlur.png");
	newImgGray.save("pictures\\Gray.png");
	newImgSepia.save("pictures\\Sepia.png");
	newImgBright.save("pictures\\Bright.png");

}
