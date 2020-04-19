#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Bakaeva_tomogram_visualizer.h"

class Bakaeva_tomogram_visualizer : public QMainWindow
{
    Q_OBJECT

public:
    Bakaeva_tomogram_visualizer(QWidget *parent = Q_NULLPTR);

private:
    Ui::Bakaeva_tomogram_visualizerClass ui;
};
