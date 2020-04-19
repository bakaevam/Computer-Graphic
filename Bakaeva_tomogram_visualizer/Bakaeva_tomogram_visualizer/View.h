#ifndef _VIEW_H_
#define _VIEW_H_
#include <QGLWidget>
#include <QtOpenGL>
#include <QTimer>
#include <qdebug.h>

#include "Data.h"
#include <qimage.h>
#include <algorithm>

class View : public QGLWidget
{
    Q_OBJECT

private:
    Data data;
    int layer; //����, ������� ����� �����������������

    void Up();
    void Down();
    void Up10();
    void Down10();

    static const int MAX_WIN_SIZE = 1000;
    static const int MIN_WIN_SIZE = 250;

    int visualization_state = 1;

    static const int VISUALIZATION_QUARDS = 0;
    static const int VISUALIZATION_QUARDSTRIP = 1;
    static const int VISUALIZATION_TEXTURE = 2;

    void changeLayer();

    QColor TransferFunction(short value);

    void VisualizationQuards();
    void VisualizationQuardStrip();
    void VisualizationTexture();
    void genTextureImage();

    //���������������
    QImage textureImage;
    GLuint VBOtexture; //����� �������� � ������ ����������
    void Load2DTexture();

public:
    View(QGLWidget* parent = Q_NULLPTR);
    ~View() {};

    void LoadData(QString fileName);
    int clamp(int value, int min, int max);

protected:
    void paintGL(); // ����� ��� ������ ����������� �� �����
    void resizeGL(int newWidth, int newHeight); // �����, ���������� ����� ������� ��������� ������� ����
    void initializeGL(); //����� ��� ����������������� OpenGL

public slots:
    void keyPressEvent(QKeyEvent* event) override; //��������� ������� ������
};
#endif