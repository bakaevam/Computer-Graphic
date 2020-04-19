#ifndef _DATA_H_
#define _DATA_H_
#include <qstring.h>

class Data
{
public:
    float scaleX, scaleY, scaleZ; //������� ������ �������
    short* arr; // ���������� ������
    int height, width, depth; // ������ ����������
    short max, min; // ����������� � ������������ ���������

    Data();
    ~Data();

    short getMin();
    short getMax(); 

    int getWidth();
    int getHeight();
    int getDepth();

    void MinMax(); // ����� min � max � ���������� ������
    short& operator[](const int idx);

    int readFile(QString fileName); //��������� ����
};
#endif

