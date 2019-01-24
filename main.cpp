#include "mainwindow.hpp"
#include <QApplication>
#include "interface.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Interface w;
    w.show();


    return a.exec();
}
