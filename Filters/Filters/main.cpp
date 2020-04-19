#include <QtCore/QCoreApplication>
#include <qimage.h>
#include <string.h>
#include <iostream>
#include "Spot_Filters.h"
#include "Matrix_Filters.h"
#include "Morphology.h"
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
	newImgBlur = blur->calculateNewImagePixMap(img, 1);

	QImage newImgGausBlur(img);
	Gaussian_blur_filter* Gausblur = new Gaussian_blur_filter();
	newImgGausBlur = Gausblur->calculateNewImagePixMap(img, 3);

	QImage newImgGray(img);
	GrayScaleFilter* gray = new GrayScaleFilter();
	newImgGray = gray->calculateNewImagePixMap(img, 0);

	QImage newImgSepia(img);
	SepiaFilter* sepia = new SepiaFilter();
	newImgSepia = sepia->calculateNewImagePixMap(img, 0);

	QImage newImgBright(img);
	BrightnessFilter* bright = new BrightnessFilter();
	newImgBright = bright->calculateNewImagePixMap(img, 0);

	QImage newImgSobelOX(img);
	Sobel_filter_OX* sobelOX = new Sobel_filter_OX();
	newImgSobelOX = sobelOX->calculateNewImagePixMap(img, 1);

	QImage newImgSobelOY(img);
	Sobel_filter_OY* sobelOY = new Sobel_filter_OY();
	newImgSobelOY = sobelOY->calculateNewImagePixMap(img, 1);

	QImage newImgSharpness_01(img);
	Sharpness_filter_01* sharp01 = new Sharpness_filter_01();
	newImgSharpness_01 = sharp01->calculateNewImagePixMap(img, 1);

	QImage newImgSharpness_02(img);
	Sharpness_filter_02* sharp02 = new Sharpness_filter_02();
	newImgSharpness_02 = sharp02->calculateNewImagePixMap(img, 1);

	QImage newImgEmbossing(img);
	Embossing_filter* emboss = new Embossing_filter();
	newImgEmbossing = emboss->calculateNewImagePixMap(img, 1, 128, true);
	newImgEmbossing = gray->calculateNewImagePixMap(newImgEmbossing, 0);

	QImage newImgWave_01(img);
	WaveFilter_01* wave01 = new WaveFilter_01();
	newImgWave_01 = wave01->calculateNewImagePixMap(img, 1);

	QImage newImgWave_02(img);
	WaveFilter_02* wave02 = new WaveFilter_02();
	newImgWave_02 = wave02->calculateNewImagePixMap(img, 1);

	bool* mask = new bool[3 * 3];
	mask[0] = false;
	mask[1] = true;
	mask[2] = false;
	mask[3] = true;
	mask[4] = true;
	mask[5] = true;
	mask[6] = false;
	mask[7] = true;
	mask[8] = false;

	QImage newImgDilation(img);
	Morphology* dilationOper = new Morphology();
	newImgDilation = dilationOper->Dilation(img, mask);

	QImage newImgErosion(img);
	Morphology* erosionOper = new Morphology();
	newImgErosion = erosionOper->Erosion(img, mask);

	QImage newImgClosing(img);
	Morphology* closingOper = new Morphology();
	newImgClosing = closingOper->Closing(img, mask);

	QImage newImgOpening(img);
	Morphology* openingOper = new Morphology();
	newImgOpening = openingOper->Opening(img, mask);

	QImage newImgTopHat(img);
	Morphology* topHatOper = new Morphology();
	newImgTopHat = topHatOper->TopHat(img, mask);

	QImage newImgBlackHat(img);
	Morphology* blackHatOper = new Morphology();
	newImgBlackHat = blackHatOper->BlackHat(img, mask);

	newImg.save("pictures\\Invert.png");
	newImgBlur.save("pictures\\Blur.png");
	newImgGausBlur.save("pictures\\GausBlur.png");
	newImgGray.save("pictures\\Gray.png");
	newImgSepia.save("pictures\\Sepia.png");
	newImgBright.save("pictures\\Bright.png");
	newImgSobelOX.save("pictures\\SobelOX.png");
	newImgSobelOY.save("pictures\\SobelOY.png");
	newImgSharpness_01.save("pictures\\Sharpness_01.png");
	newImgSharpness_02.save("pictures\\Sharpness_02.png");
	newImgEmbossing.save("pictures\\Embossing.png");
	newImgWave_01.save("pictures\\Wave_01.png");
	newImgWave_02.save("pictures\\Wave_02.png");
	newImgDilation.save("pictures\\Dilation.png");
	newImgErosion.save("pictures\\Erosion.png");
	newImgClosing.save("pictures\\Closing.png");
	newImgOpening.save("pictures\\Opening.png");
	newImgTopHat.save("pictures\\Top_Hat.png");
	newImgBlackHat.save("pictures\\Black_Hat.png");
}
