#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "cmath"

static Planete terre (0, 0, 5.9722e24, 6.378e6, 0, 0);

MainWindow::MainWindow(double altitude, double v0, string methode, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    satellite (terre.getR() + altitude, 0, 0, v0, 100, terre), methode(methode), t(0)

{
    ui->setupUi(this);

    setupgraph(ui->xSatellite, ui->ySatellite, ui->VxSatellite, ui->VySatellite, terre, satellite, t);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupgraph(QCustomPlot *plotx, QCustomPlot *ploty,
                             QCustomPlot *plotvx, QCustomPlot *plotvy,
                             Planete & planete, Satellite & satellite, double & t){
    QVector<double> tps, x, y, vx, vy;
    while(t<86400){
        if ( satellite.distance(terre) <= terre.getR() ) {
            break;
        }
        tps.append(t);
        x.append(satellite.getX());
        y.append(satellite.getY());
        vx.append(satellite.getVx());
        vy.append(satellite.getVy());

        if (methode == "RungeKutta"){
            RKPlanet(t, terre, satellite);
        }
        else if (methode == "TangenteAmeliore"){
            TangenteAmilorePlanet(t, terre, satellite);
        }
        else {
            eulerPlanet(t, terre, satellite);
        }
    }

    // create graph and assign data to it:
    plotx->addGraph();
    plotx->graph(0)->setData(tps, x);

    ploty->addGraph();
    ploty->graph(0)->setData(tps, y);

    plotvx->addGraph();
    plotvx->graph(0)->setData(tps, vx);

    plotvy->addGraph();
    plotvy->graph(0)->setData(tps, vy);

    // give the axes some labels:
    plotx->xAxis->setLabel("t");
    plotx->yAxis->setLabel("X");

    ploty->xAxis->setLabel("t");
    ploty->yAxis->setLabel("Y");

    plotvx->xAxis->setLabel("t");
    plotvx->yAxis->setLabel("Vx");

    plotvy->xAxis->setLabel("t");
    plotvy->yAxis->setLabel("Vy");

    // set axes ranges, so we see all data:
    plotx->xAxis->setRange(0, 86400);
    ploty->xAxis->setRange(0, 86400);
    plotvx->xAxis->setRange(0, 86400);
    plotvy->xAxis->setRange(0, 86400);

    double k1 = sqrt ( (satellite.getX())*(satellite.getX()) + (satellite.getY())*(satellite.getY()) ) + 10000;
    double k2 = sqrt ( (satellite.getVx())*(satellite.getVx()) + (satellite.getVy())*(satellite.getVy()) ) + 10;

    plotx->yAxis->setRange(-k1, k1);
    ploty->yAxis->setRange(-k1, k1);
    plotvx->yAxis->setRange(-k2, k2);
    plotvy->yAxis->setRange(-k2, k2);

    plotx->replot();
    ploty->replot();
    plotvx->replot();
    plotvy->replot();
}




