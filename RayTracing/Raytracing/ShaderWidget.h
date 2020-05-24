#ifndef SHADERWIDGET_H
#define SHADERWIDGET_H
#include <qtopengl>
#include <qopenglwidget.h>
#include <qimage.h>
#include <algorithm>

class ShaderWidget : public QOpenGLWidget
{
protected:
    void initializeGL() override;
    void resizeGL(int newWidth, int newHeight) override;
    void paintGL() override;

public:
    ShaderWidget(QWidget* parent = 0);
    ~ShaderWidget();

private:
    //Подключение шейдеров к основной программе
    QOpenGLShaderProgram m_program;

    GLfloat* vert_data;
    //Расположение массива в пределах списка параметров шейдерной программы
    int vert_data_location;
};

#endif