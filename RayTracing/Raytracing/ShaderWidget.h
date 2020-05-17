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
    QOpenGLShaderProgram m_program;

    GLfloat* vert_data;
    int vert_data_location;
};

#endif