#ifndef _VIEW_H_
#define _VIEW_H_
#include <QGLWidget>
#include <QtOpenGL>
#include <qdebug.h>

#include "Data.h"
#include <qimage.h>
#include <algorithm>

class View : public QGLWidget
{
    Q_OBJECT

public:
    View(QGLWidget* parent = Q_NULLPTR);
    ~View() {};

    void LoadData(QString fileName);
    int clamp(int value, int min, int max);

private:
    Data data;
    int layer; //Слой, который будет визуализироваться
    int axis = 3;

    void Up();
    void Down();

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

    //Текстурирование
    QImage textureImage;
    GLuint VBOtexture; //Номер текстуры в памяти видеокарты
    void Load2DTexture();

protected:
    void paintGL() override; // Метод для вывода изображения на экран
    void resizeGL(int newWidth, int newHeight) override; // Метод, вызываемый после каждого изменения размера окна
    void initializeGL() override; //Метод для инициализирования OpenGL
    void openMinMaxDialog();

public slots:
    void keyPressEvent(QKeyEvent* event) override; //Обработка нажатия клавиш
};

#endif