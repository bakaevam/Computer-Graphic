#include "Bakaeva_tomogram_visualizer.h"
#include <QtWidgets/QApplication>
#include "Data.h"
#include "View.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    View w(NULL);
    w.LoadData("..\\Bakaeva_tomogram_visualizer\\data\\testdata.bin");
    w.show();
    return a.exec();
}
