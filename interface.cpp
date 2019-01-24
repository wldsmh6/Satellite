#include "interface.hpp"
#include "ui_interface.h"
#include <QPainter>

Interface::Interface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);
    ui->VitesseInitiale->setMaximum(1000000);
    ui->AltitudeInitiale->setMaximum(1000000000);
    ui->VitesseInitiale->setValue(3074);
    ui->AltitudeInitiale->setValue(35784000);
    ui->start->setEnabled(false);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height()/2;
    int width = screenGeometry.width()/2;
    this->setFixedSize(width,height);

    QPixmap bkgnd(":/interface.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QPainter painter(this);
    double scale=100000;
    painter.setBrush(Qt::darkBlue);
    QPoint point(0,0);
    painter.drawEllipse(point,(0),(0));
}

Interface::~Interface()
{
    delete ui;
}

void Interface::on_start_clicked()

{
       if (ui->simulation->isChecked()) {
           h = ui->AltitudeInitiale->value();
           v0 = ui->VitesseInitiale->value();
           Space * sim = new Space(h, v0, methode);
           sim->show();
       }
       if (ui->graphes->isChecked()) {
           h = ui->AltitudeInitiale->value();
           v0 = ui->VitesseInitiale->value();
           MainWindow * plot = new MainWindow(h, v0, methode);
           plot->show();
       }

       this->~Interface();
}


void Interface::on_cancel_clicked()
{
    this->~Interface();
}



void Interface::on_RungeKutta_toggled(bool checked)
{
    if (checked) {
        methode = "RungeKutta";
        ui->start->setEnabled(true);
    }
}

void Interface::on_TangenteAmeliore_toggled(bool checked)
{
    if (checked) {
        methode = "TangenteAmeliore";
        ui->start->setEnabled(true);
    }
}

void Interface::on_Euler_toggled(bool checked)
{
    if (checked) {
        methode = "Euler";
        ui->start->setEnabled(true);
    }
}
