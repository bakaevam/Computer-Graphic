#include "ShaderWidget.h"

ShaderWidget::ShaderWidget(QWidget* parent):QOpenGLWidget(parent), vert_data_location(0)
{
    vert_data = new GLfloat[12];

    //x y z
    vert_data[0] = -1.0f;  vert_data[1] = -1.0f;  vert_data[2] = 0.0f;
    vert_data[3] = 1.0f;  vert_data[4] = -1.0f;  vert_data[5] = 0.0f;
    vert_data[6] = 1.0f;  vert_data[7] = 1.0f;  vert_data[8] = 0.0f;
    vert_data[9] = -1.0f;  vert_data[10] = 1.0f;  vert_data[11] = 0.0f;
};

ShaderWidget::~ShaderWidget()
{
    delete[] vert_data;
};

void ShaderWidget::initializeGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    QOpenGLShader vShader(QOpenGLShader::Vertex);
    vShader.compileSourceFile("raytracing.vert");

    QOpenGLShader fShader(QOpenGLShader::Fragment);
    fShader.compileSourceFile("raytracing.frag");

    m_program.addShader(&vShader);
    m_program.addShader(&fShader);

    if (!m_program.link())
    {
        qWarning("Error link program shader");
        return;
    }

    vert_data_location = m_program.attributeLocation("vertex");

    qDebug() << QString("Log program");
    qDebug() << m_program.log();
};

void ShaderWidget::resizeGL(int newWidth, int newHeight)
{
    glViewport(0, 0, newWidth, newHeight);
};

void ShaderWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (!m_program.bind())
        return;

    m_program.enableAttributeArray(vert_data_location);
    m_program.setAttributeArray(vert_data_location, vert_data, 3);

    glDrawArrays(GL_QUADS, 0, 4);

    m_program.disableAttributeArray(vert_data_location);
    m_program.release();
};