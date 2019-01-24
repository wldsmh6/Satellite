#ifndef INTERFACE_H
#define INTERFACE_H

#include <QDialog>
#include <QPalette>
#include <QScreen>
#include <QRect>
#include <string>
#include "space.hpp"
#include "mainwindow.hpp"

namespace Ui {
class Interface;
}

class Interface : public QDialog
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = 0);
    ~Interface();

private slots:
    void on_cancel_clicked();

    void on_start_clicked();

    void on_RungeKutta_toggled(bool checked);

    void on_TangenteAmeliore_toggled(bool checked);

    void on_Euler_toggled(bool checked);

private:
    Ui::Interface *ui;
    double h;
    double v0;
    string methode;
};

#endif // INTERFACE_H
