#include "ShaderWidget.h"

ShaderWidget::ShaderWidget(QWidget* parent) :QOpenGLWidget(parent), vert_data_location(0)
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

    //����� ����������� ������������� ������ (��� Vertex)
    QOpenGLShader vShader(QOpenGLShader::Vertex);
    /*���������� ������� � ������� QOpenGLContext
    ��������� ��������� ���� ��� �������, ������������� � �����, � ����������*/
    vShader.compileSourceFile("raytracing.vert");

    QOpenGLShader fShader(QOpenGLShader::Fragment);
    fShader.compileSourceFile("raytracing.frag");

    //���������� ���������������� �������� � ��������� ���������
    m_program.addShader(&vShader);
    m_program.addShader(&fShader);

    //link - ��������� ����� ����� �������
    if (!m_program.link())
    {
        qWarning("Error link program shader");
        return;
    }

    qDebug() << QString("Log program");
    qDebug() << m_program.log();

    //���������� ������������ ����� ��������(vertex) � ������ ���������� ��������� ���������
    vert_data_location = m_program.attributeLocation("vertex");

    if (!m_program.bind())
        qWarning("Error bind program shader");

    m_program.setUniformValue("camera.position", QVector3D(0.0, 0.0, -10));
    m_program.setUniformValue("camera.view", QVector3D(0.0, 0.0, 1.0));
    m_program.setUniformValue("camera.up", QVector3D(0.0, 1.0, 0.0));
    m_program.setUniformValue("camera.side", QVector3D(1.0, 0.0, 0.0));

    m_program.setUniformValue("spheres[0].Centre", QVector3D(-1.0, -1.0, -2.0));
    m_program.setUniformValue("spheres[0].Radius", 2.0f);
    m_program.setUniformValue("spheres[0].Color", QVector3D(1.0, 0.0, 0.0));

    m_program.setUniformValue("spheres[1].Centre", QVector3D(2.0, 1.0, 2.0));
    m_program.setUniformValue("spheres[1].Radius", 1.0f);
    m_program.setUniformValue("spheres[1].Color", QVector3D(0.0, 1.0, 0.0));

    m_program.setUniformValue("scale", QVector2D(width(), height()));

    m_program.release();
};

void ShaderWidget::resizeGL(int newWidth, int newHeight)
{
    glViewport(0, 0, newWidth, newHeight);
    if (!m_program.bind())
        qWarning("Error bind program shader");

    m_program.setUniformValue("scale", QVector2D(width(), height()));
    m_program.release();
};

void ShaderWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //bind - ��������� ��������� ��������� � �������� QOpenGLContext � ������ � �������.
    if (!m_program.bind())
        return;

    //��������� ������������� ������� �������� ��������� ������ ��� ��������� ���������� � ��������� ���������
    m_program.enableAttributeArray(vert_data_location);
    //������������� ������ �������� ��������� ������ � ��������� ���������
    m_program.setAttributeArray(vert_data_location, vert_data, 3);

    //��� ���������; ������ �������, � ������� ����� �������� ������; ���������� ������
    glDrawArrays(GL_QUADS, 0, 4);

    //���������� ������� ������
    m_program.disableAttributeArray(vert_data_location);
    //��������� �������� ��������� ���������
    m_program.release();
};