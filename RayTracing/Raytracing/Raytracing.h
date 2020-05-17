#ifndef RAYTRACING_H
#define RAYTRACING_H

#include <QtWidgets/QMainWindow>
#include "ui_Raytracing.h"

class Raytracing : public QMainWindow
{
    Q_OBJECT

public:
    Raytracing(QWidget *parent = Q_NULLPTR);

private:
    Ui::RaytracingClass ui;
};

#endif