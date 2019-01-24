#ifndef TANGENTEAMELIORE_H
#define TANGENTEAMELIORE_H

#include <cmath>
#include "planete.hpp"
#include "satellite.hpp"

double fxTa(double t, double x, double y, double vx, double vy, double xt, double yt);
double fyTa(double t, double x, double y, double vx, double vy, double xt, double yt);
double gxTa(double t, double x, double y, double vx, double vy, double xt, double yt);
double gyTa(double t, double x, double y, double vx, double vy, double xt, double yt);

void TangenteAmeliore(double(*g1)(double t, double x, double y, double vx, double vy, double xt, double yt),
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

double TangenteAmilorePlanet (double & t, Planete & planete, Satellite & satellite);

#endif // TANGENTEAMELIORE_H
