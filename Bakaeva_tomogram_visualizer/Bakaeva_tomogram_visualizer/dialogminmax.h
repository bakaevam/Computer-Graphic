#ifndef DIALOGMINMAX_H
#define DIALOGMINMAX_H

#include <QDialog>
#include <qlineedit.h>

namespace Ui {
class DialogMinMax;
}

class DialogMinMax : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMinMax(QWidget *parent = nullptr);
    ~DialogMinMax();
    short min;
    short max;

    short getMin() const;
    short getMax() const;

private slots:
    void slot1();

private:
    Ui::DialogMinMax *ui;
};

#endif // DIALOGMINMAX_H
