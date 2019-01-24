#include "space.hpp"
#include "ui_space.h"
#include <iostream>
#include <sstream>
#include <QFont>

static Planete terre (0, 0, 5.9722e24, 6.378e6, 0, 0);

Space::Space(double h, double v0, string methode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Space), satellite (terre.getR() + h, 0, 0, v0, 100, terre), methode(methode), t(0)
{
    ui->setupUi(this);

    connect(&timer,SIGNAL(timeout()),this,SLOT(updateSim()));
    timer.setSingleShot(false);
    timer.setInterval(1);
    timer.start();

    //to fix the window size equal to the screen's size
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    this->setFixedSize(width,height);

    //to change te background
    QPixmap bkgnd(":/Space.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    scale = (100000);
    rs = (10);

    Oy=this->frameSize().height()/2;
    Ox=this->frameSize().width()/2;
    xs = Ox + satellite.getX() / scale;
    ys = Oy + satellite.getY() / scale;

}

void Space::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setBrush(Qt::darkBlue);
    QPoint pointterre(Ox,Oy);
    painter.drawEllipse(pointterre,(terre.getR()/scale-rs),(terre.getR()/scale-rs));

    painter.setBrush(Qt::yellow);
    QPoint pointsatellite(xs, ys);
    painter.drawEllipse(pointsatellite, rs, rs);
}


Space::~Space()
{
    delete ui;
}

void Space::updateSim() {

    cout << t <<"      " << satellite.getX()<<"     "<<satellite.getY()<<endl;
    if (methode == "RungeKutta"){
        RKPlanet(t, terre, satellite);
    }
    else if (methode == "TangenteAmeliore"){
        TangenteAmilorePlanet(t, terre, satellite);
    }
    else {
        eulerPlanet(t, terre, satellite);
    }


    //set label x
    string labelx = toString(satellite.getX());

    ui->labelX->setText("<font color='red'> x: " + QString::fromStdString(labelx) );
    QFont fontx = ui->labelX->font();
    fontx.setPointSize(15);
    fontx.setBold(true);
    ui->labelX->setFont(fontx);
    //set label y
    string labelY = toString(satellite.getY());

    ui->labelY->setText("<font color='red'> Y: " + QString::fromStdString(labelY) );
    QFont fonty = ui->labelY->font();
    fonty.setPointSize(15);
    fonty.setBold(true);
    ui->labelY->setFont(fonty);
    //set label vx
    string labelVx = toString(satellite.getVx());

    ui->labelVx->setText("<font color='red'> Vx: " + QString::fromStdString(labelVx) );
    QFont fontVx = ui->labelVx->font();
    fontVx.setPointSize(15);
    fontVx.setBold(true);
    ui->labelVx->setFont(fontVx);
    //set label vy
    string labelVy = toString(satellite.getVy());

    ui->labelVy->setText("<font color='red'> Vy: " + QString::fromStdString(labelVy) );
    QFont fontVy = ui->labelVy->font();
    fontVy.setPointSize(15);
    fontVy.setBold(true);
    ui->labelVy->setFont(fontVy);


    QMessageBox msgBox;
    if ( satellite.distance(terre) <= terre.getR() + rs ) {
        timer.stop();
        msgBox.setText("Your satellite just crashed!!");
        msgBox.exec();
    }

    else if (xs > Ox*2 || ys > Oy*2) {
        cout <<" STOP ";
        timer.stop();;
        msgBox.setText("Your satellite got away from the earth");
        msgBox.exec();
    }

    update();
    xs = Ox + satellite.getX() / scale;
    ys = Oy + satellite.getY() / scale;

}

string Space::toString (double x) {
    stringstream out;
    out << x;
    return out.str();

}


