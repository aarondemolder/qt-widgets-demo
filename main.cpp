#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //init the application
    QApplication a(argc, argv);
    //init the window
    MainWindow w;
    //show the window
    w.show();
    return a.exec();
}
