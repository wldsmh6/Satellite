#include "euler.hpp"

static double const G = 6.67408e-11;  //constante gravitationelle
static double M; //masse de la terre
static double const dt = 10;    //pas de temps

double fxe(double t, double x, double y, double vx, double vy, double xt, double yt)  //derivee seconde en x
{
    double r2;
    r2 = (x - xt)*(x - xt) + (y - yt)*(y - yt);
    double r = sqrt(r2);
    double res = -G*M*(x - xt);
    res /= r;
    res /= r2;
    return res;
}


double fye(double t, double x, double y, double vx, double vy, double xt, double yt)  //derivee seconde en y
{
    double r2;
    r2 = (x - xt)*(x - xt) + (y - yt)*(y - yt);
    double r = sqrt(r2);
    double res = -G*M*(y - yt);
    res /= r;
    res /= r2;
    return res;
}

double gxe(double t, double x, double y, double vx, double vy, double xt, double yt) //vitesse en x
{
    return vx;
}

double gye(double t, double x, double y, double vx, double vy, double xt, double yt)  //vitesse en y
{
    return vy;
}


void euler(double(*g1)(double t, double x, double y, double vx, double vy, double xt, double yt),
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
    double yt)
{
    double kx = g1(t, x, y, vx, vy, xt, yt);
    double ky = g2(t, x, y, vx, vy, xt, yt);
    double kvx = g3(t, x, y, vx, vy, xt, yt);
    double kvy = g4(t, x, y, vx, vy, xt, yt);

    t = t + dt;
    x = x + dt*kx;
    y = y + dt*ky;
    vx = vx + dt*kvx;
    vy = vy + dt*kvy;

}

double eulerPlanet (double & t, Planete & planete, Satellite & satellite) {
    M = planete.getM();
    double x = satellite.getX();
    double y = satellite.getY();
    double vx = satellite.getVx();
    double vy = satellite.getVy();

    euler(gxe, gye, fxe, fye, t, x, y,vx, vy, dt, planete.getX(), planete.getY());

    satellite.setX(x);
    satellite.setY(y);
    satellite.setVx(vx);
    satellite.setVy(vy);

}

