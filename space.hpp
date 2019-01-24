#ifndef SPACE_H
#define SPACE_H

#include <QDialog>
#include <QPainter>
#include <QRect>
#include <QScreen>
#include <QTimer>
#include <QString>
#include <QMessageBox>
#include <string>
#include <cmath>
#include "objetspacial.hpp"
#include "planete.hpp"
#include "satellite.hpp"
#include "RungeKutta.hpp"
#include "euler.hpp"
#include "tangenteameliore.hpp"
#include "mainwindow.hpp"

namespace Ui {
class Space;
}

class Space : public QDialog
{
    Q_OBJECT

public:
    explicit Space(double h, double v0, string methode, QWidget *parent = 0);
    string toString (double x);
    ~Space();
    void crash ();

private slots:
    void paintEvent(QPaintEvent *event);
    void updateSim ();

private:
    Ui::Space *ui;
    double Ox, Oy, xs, ys;
    double scale;
    double rs;
    Satellite satellite;
    double t;
    string methode;
    QTimer timer;
};

#endif // SPACE_H
