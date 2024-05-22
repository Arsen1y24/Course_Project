#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(/*Qt::FramelessWindowHint | */Qt::Window | Qt::WindowStaysOnTopHint);
    //w.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    //w.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
   // w.setWindowFlags();
    //w.setWindowFlag(Qt::CustomizeWindowHint, true);
    //w.setWindowFlag(Qt::WindowTitleHint, true);
    //w.setWindowFlag(Qt::WindowSystemMenuHint, false);
    w.resize(1650, 950);
    w.show();
    return a.exec();
}
