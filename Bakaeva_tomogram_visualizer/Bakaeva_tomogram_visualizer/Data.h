#ifndef _DATA_H_
#define _DATA_H_
#include <qstring.h>

class Data
{
public:
    float scaleX, scaleY, scaleZ; //Размеры одного вокселя
    short* arr; // Воксельная модель
    int height, width, depth; // Размер томограммы
    short max, min; // Минимальная и максимальная плотность

    Data();
    ~Data();

    short getMin();
    short getMax(); 

    int getWidth();
    int getHeight();
    int getDepth();

    void MinMax(); // Поиск min и max в воксельной модели
    short& operator[](const int idx);

    int readFile(QString fileName); //Прочитать файл
};
#endif

