#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "qcustomplot.h"
#include "objetspacial.hpp"
#include "planete.hpp"
#include "satellite.hpp"
#include "RungeKutta.hpp"
#include "euler.hpp"
#include "tangenteameliore.hpp"
#include "string"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(double altitude, double v0, string methode, QWidget *parent = 0);
    void setupgraph(QCustomPlot *plotx, QCustomPlot *ploty,
                     QCustomPlot *plotvx, QCustomPlot *plotv,
                     Planete & planete, Satellite & satellite, double & t);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Satellite satellite;
    double t;
    string methode;
};

#endif // MAINWINDOW_H
