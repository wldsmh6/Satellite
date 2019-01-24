#ifndef EULER_H
#define EULER_H

#include <cmath>
#include "planete.hpp"
#include "satellite.hpp"

double fxe(double t, double x, double y, double vx, double vy, double xt, double yt);
double fye(double t, double x, double y, double vx, double vy, double xt, double yt);
double gxe(double t, double x, double y, double vx, double vy, double xt, double yt);
double gye(double t, double x, double y, double vx, double vy, double xt, double yt);

void Euler(double(*g1)(double t, double x, double y, double vx, double vy, double xt, double yt),
    double(*g2)(double t, double x, double y, double vx, double vy, double xt, double yt),
    double(*g3)(double t, double x, double y, double vx, double vy, double xt, double yt),
    double(*g4)(double t, double x, double y, double vx, double vy, double xt, double yt),
    double &t,
    double &x,
    double &y,
    double &vx,
    double &vy,
    double dt,
    double xt,
    double yt);

double eulerPlanet (double & t, Planete & planete, Satellite & satellite);



#endif // EULER_H
