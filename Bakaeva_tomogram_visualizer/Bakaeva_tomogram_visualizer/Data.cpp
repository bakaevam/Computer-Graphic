#include "Data.h"
#include <locale>
#include <iostream>
#include <fstream>
#include <qdebug.h>
using namespace std;

Data::Data()
{
    height = width = depth = 0;
    min = max = 0;
    scaleX = scaleY = scaleZ = 0;
    arr = NULL;
};

Data::~Data()
{
    height = width = depth = 0;
    delete[] arr;
}

short Data::getMin()
{
    return min;
};

short Data::getMax()
{
    return max;
};

int Data::getWidth()
{
    return width;
};

int Data::getHeight()
{
    return height;
};

int Data::getDepth()
{
    return depth;
};

void Data::MinMax()
{
    max = min = arr[0];
    for (int i = 0; i < height * width * depth; i++)
    {
        if (min > arr[i])
            min = arr[i];

        if (max < arr[i])
            max = arr[i];
    }

    qDebug() << "Min = " << min << ", Max = " << max;
};

short& Data::operator[](const int idx)
{
    // сообщение об ошибке
    assert(idx >= 0 && idx < height * width * depth);
    return arr[idx];
};

int Data::readFile(QString fileName)
{
    setlocale(0, "RUS");

    //Чтение всего файла в переменную file
    ifstream file;
    //ios::binary - режим чтения бинарного файла
    //ios::in - режим чтения файла
    file.open(fileName.toStdString(), ios::binary | ios::in);

    if (!file.is_open()) //Если файл не открыт
        qDebug() << "File wasn't opened!\n"; //Логирование

    int x, y, z;
    qDebug() << QString("Open");

    // Чтение размера томограммы
    file.read((char*)&x, sizeof(int));
    file.read((char*)&y, sizeof(int));
    file.read((char*)&z, sizeof(int));

    if (x == 0 || y == 0 || z == 0)
    {
        qDebug() << QString(" Wrong data size");
        file.close();
        return -1;
    }

    qDebug() << " Width = " << x << ", Height = " << y << ", Depth = " << z;

    // Чтение размеров одного вокселя
    file.read((char*)&scaleX, sizeof(float));
    file.read((char*)&scaleY, sizeof(float));
    file.read((char*)&scaleZ, sizeof(float));

    if (scaleX == 0 || scaleY == 0 || scaleZ == 0)
    {
        qDebug() << QString(" Wrong data scale size");
        file.close();
        return -1;
    }

    qDebug() << " ScaleX = " << scaleX << 
        ", ScaleY = " << scaleY << ", ScaleZ = " << scaleZ;

    if (arr != NULL)
        delete[] arr;

    width = x;
    height = y;
    depth = z;

    // Размер воксельной модели
    long sizeArr = height * depth * width;

    arr = new short[sizeArr];
    file.read((char*)arr, sizeArr * sizeof(short));
    file.close();
    qDebug() << QString("Close");

    MinMax();

    return 0;
};