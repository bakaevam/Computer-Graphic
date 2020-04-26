#include "dialogminmax.h"
#include "ui_dialogminmax.h"
#include <qdebug.h>

DialogMinMax::DialogMinMax(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMinMax)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slot1()));
}

DialogMinMax::~DialogMinMax()
{
    delete ui;
}

void DialogMinMax::slot1()
{
    min = ui->minLineEdit->text().toShort();
    max = ui->maxLineEdit->text().toShort();

    accept();
};

short DialogMinMax::getMin() const
{
    return min;
};

short DialogMinMax::getMax() const
{
    return max;
};

