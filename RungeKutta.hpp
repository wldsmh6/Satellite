#ifndef RungeKutta_H
#define RungeKutta_H

#include <cmath>
#include "planete.hpp"
#include "satellite.hpp"



    double fx(double t, double x, double y, double vx, double vy, Planete planete);  //derivee seconde en x
    double fy(double t, double x, double y, double vx, double vy, Planete planete);  //derivee seconde en y
    double gx(double t, double x, double y, double vx, double vy, Planete planete); //vitesse en x
    double gy(double t, double x, double y, double vx, double vy, Planete planete);  //vitesse en y

    void RK(double(*g1)(double t, double x, double y, double vx, double vy, Planete planete),
        double(*g2)(double t, double x, double y, double vx, double vy, Planete planete),
        double(*g3)(double t, double x, double y, double vx, double vy, Planete planete),
        double(*g4)(double t, double x, double y, double vx, double vy, Planete planete),
        double &t,
        double &x,
        double &y,
        double &vx,
        double &vy,
        double dt,
        Planete planete);

    double RKPlanet (double & t, Planete & planete, Satellite & satellite);



#endif // RungeKutta_H
