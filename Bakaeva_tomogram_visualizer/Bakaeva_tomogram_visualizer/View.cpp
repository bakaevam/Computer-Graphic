#include "View.h"
#include "Data.h"
#include "DialogMinMax.h"
#include <qobject.h>


void View::initializeGL()
{
    qglClearColor(Qt::white); // ��������� ������������ �����
    glShadeModel(GL_SMOOTH); //��������� ������ �����������
    glMatrixMode(GL_MODELVIEW); //������� ��������-������� �������
    glLoadIdentity(); //�������� ��������� �������

    glGenTextures(1, &VBOtexture); // ��������� ����������� ������ ��������
};

void View::resizeGL(int newWidth, int newHeight)
{
    //��������������� ��������
    glMatrixMode(GL_PROJECTION); //�������� �������
    glLoadIdentity(); //�������� ��������� �������
    glOrtho(0.0f, data.getWidth() - 1, 0.0f,
        data.getHeight() - 1, -1.0f, 1.0f); //��������� �������������� ������� ���������
    glViewport(0, 0, newWidth, newHeight); // ��������� ���� ������, ����� ��� �� ������� � �������
    update();
};

void View::paintGL()
{
    qDebug() << "Repaint" << visualization_state;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //������� ������� ����� � ������� (������� ������)

    switch (visualization_state)
    {
    case VISUALIZATION_QUARDS:
        VisualizationQuards();
        break;

    case VISUALIZATION_QUARDSTRIP:
        VisualizationQuardStrip();
        break;

    case VISUALIZATION_TEXTURE:
        VisualizationTexture();
        break;
    }
};

QColor View::TransferFunction(short value)
{
    int c = (value - data.getMin()) * 255 / (data.getMax() - data.getMin());
    c = clamp(c, 0, 255);
    return QColor(c, c, c);
};

void View::VisualizationQuards()
{
    QColor c;
    int w = data.getWidth();
    int h = data.getHeight();

    glBegin(GL_QUADS);

    for(int y = 0; y < (h - 1); y++)
        for (int x = 0; x < (w - 1); x++)
        {
            // ���������� ��������, ������� ����� �������� - ���������������

            c = TransferFunction(data[layer * w * h + y * w + x]);
            qglColor(c);
            glVertex2i(x, y);

            c = TransferFunction(data[layer * w * h + (y + 1) * w + x]);
            qglColor(c);
            glVertex2i(x, (y + 1));

            c = TransferFunction(data[layer * w * h + (y + 1) * w + x + 1]);
            qglColor(c);
            glVertex2i((x + 1), (y + 1));

            c = TransferFunction(data[layer * w * h + y * w + x + 1]);
            qglColor(c);
            glVertex2i((x + 1), y);
        }

    glEnd();
};

void View::keyPressEvent(QKeyEvent* event)
{
    if (event->nativeVirtualKey() == Qt::Key_W)
    {
        //��������� �� ���� ����
        Up();
        changeLayer();
    }
    else if (event->nativeVirtualKey() == Qt::Key_S)
    {
        //���������� �� ���� ����
        Down();
        changeLayer();
    }
    else if (event->nativeVirtualKey() == Qt::Key_C)
    {
        //���� ����� �������� � ���������
        openMinMaxDialog();

        if(visualization_state == VISUALIZATION_TEXTURE)
        {
            genTextureImage();
            Load2DTexture();
        }

        update();
    }
    else if (event->nativeVirtualKey() == Qt::Key_V)
    {
        //�������� ���� ������ �����
        QFileDialog* fileDialog = new QFileDialog;
        QString newPath = fileDialog->getOpenFileName();
        LoadData(newPath);

        update();
    }
    else if (event->nativeVirtualKey() == Qt::Key_X)
    {
        resizeGL(data.getHeight(), data.getWidth());
        update();
    }
    else if (event->nativeVirtualKey() == Qt::Key_N)
    {
        //������������� �� ��������� ��� ���������
        visualization_state = (visualization_state + 1) % 3;
        if (visualization_state == VISUALIZATION_TEXTURE)
        {
            glEnable(GL_TEXTURE_2D);
            genTextureImage();
            Load2DTexture();
        }
        else
        {
            glDisable(GL_TEXTURE_2D);
        }
    }
    update(); //��������� �� ���� ����
};

void View::changeLayer()
{
    if (visualization_state == VISUALIZATION_TEXTURE)
    {
        genTextureImage();
        Load2DTexture();
    }
};

void View::Load2DTexture()
{
    //�������� ������ �������� � ��������
    glBindTexture(GL_TEXTURE_2D, VBOtexture);
    //��������� ��������, ��������� ��������� ������
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureImage.width(),
        textureImage.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, textureImage.bits());
    //��������� ��� ������� ��������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
};

void View::genTextureImage()
{
    int w = data.getWidth();
    int h = data.getHeight();
    
    textureImage = QImage(w, h, QImage::Format_RGB32);

    for(int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
        {
            QColor c = TransferFunction(data[layer * w * h + w * y + x]);
            textureImage.setPixelColor(x, y, c);
        }
};

void View::Up()
{
    if ((layer + 1) < data.getDepth())
        layer++;

    qDebug() << layer;
    update();
};

void View::Down()
{
    if ((layer - 1) >= 0)
        layer--;

    qDebug() << layer;
    update();
};

void View::Up10()
{
    if ((layer + 10) < data.getDepth())
        layer += 10;

    qDebug() << layer;
    update();
};

void View::Down10()
{
    if ((layer - 10) >= 0)
        layer -= 10;

    qDebug() << layer;
    update();
};

View::View(QGLWidget* parent): QGLWidget(parent)
{
    layer = 0;

    resizeGL(MIN_WIN_SIZE, MIN_WIN_SIZE); //������ ������� ����
    setFocus(); //������������� ������ ����������
};

void View::LoadData(QString fileName)
{
    data.readFile(fileName);
    resize(clamp(data.getWidth(), MIN_WIN_SIZE, MAX_WIN_SIZE), clamp(data.getHeight(), MIN_WIN_SIZE, MAX_WIN_SIZE));
    update();
};

int View::clamp(int value, int min, int max)
{
    if (value > max)
        return max;

    if (value < min)
        return min;

    return value;
};

void View::VisualizationTexture()
{
    glBegin(GL_QUADS);
    qglColor(QColor(255, 255, 255));

    glTexCoord2f(0, 0);
    glVertex2i(0, 0);

    glTexCoord2f(0, 1);
    glVertex2i(0, data.getHeight());

    glTexCoord2f(1, 1);
    glVertex2i(data.getWidth(), data.getHeight());

    glTexCoord2f(1, 0);
    glVertex2i(data.getWidth(), 0);

    glEnd();
};

void View::VisualizationQuardStrip()
{
    QColor c;
    int w = data.getWidth();
    int h = data.getHeight();

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
        {
            glBegin(GL_QUAD_STRIP);

            c = TransferFunction(data[layer * w * h + y * w + x]);
            qglColor(c);
            glVertex2i(x, y);

            c = TransferFunction(data[layer * w * h + (y + 1) * w + x]);
            qglColor(c);
            glVertex2i(x, (y + 1));

            c = TransferFunction(data[layer * w * h + y * w + x + 1]);
            qglColor(c);
            glVertex2i((x + 1), y);

            c = TransferFunction(data[layer * w * h + (y + 1) * w + x + 1]);
            qglColor(c);
            glVertex2i((x + 1), (y + 1));

            glEnd();
        }
};

void View::openMinMaxDialog()
{
    DialogMinMax* dialog = new DialogMinMax;
    dialog->exec();

    if(dialog->getMin() > 0)
        data.min = dialog->getMin();

    if(dialog->getMax() > 0)
        data.max = dialog->getMax();
};
