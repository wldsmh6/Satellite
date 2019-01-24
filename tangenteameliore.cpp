#include "tangenteameliore.hpp"

static double const G = 6.67408e-11;  //constante gravitationelle
static double M; //masse de la terre
static double const dt = 10;    //pas de temps

double fxTa(double t, double x, double y, double vx, double vy, double xt, double yt)  //derivee seconde en x
{
    double r2;
    r2 = (x - xt)*(x - xt) + (y - yt)*(y - yt);
    double r = sqrt(r2);
    double res = -G*M*(x - xt);
    res /= r;
    res /= r2;
    return res;
}


double fyTa(double t, double x, double y, double vx, double vy, double xt, double yt)  //derivee seconde en y
{
    double r2;
    r2 = (x - xt)*(x - xt) + (y - yt)*(y - yt);
    double r = sqrt(r2);
    double res = -G*M*(y - yt);
    res /= r;
    res /= r2;
    return res;
}

double gxTa(double t, double x, double y, double vx, double vy, double xt, double yt) //vitesse en x
{
    return vx;
}

double gyTa(double t, double x, double y, double vx, double vy, double xt, double yt)  //vitesse en y
{
    return vy;
}



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
    double yt)
{

    double k1x = dt*g1(t, x, y, vx, vy, xt, yt);
    double k1y = dt*g2(t, x, y, vx, vy, xt, yt);
    double k1vx = dt*g3(t, x, y, vx, vy, xt, yt);
    double k1vy = dt*g4(t, x, y, vx, vy, xt, yt);

    double k2x = dt*g1(t + dt, x + k1x, y + k1y, vx + k1vx, vy + k1vy, xt, yt);
    double k2y =dt* g2(t + dt, x + k1x, y + k1y, vx + k1vx, vy + k1vy, xt, yt);
    double k2vx = dt*g3(t + dt, x + k1x, y + k1y, vx + k1vx, vy + k1vy, xt, yt);
    double k2vy = dt*g4(t + dt, x + k1x, y + k1y, vx + k1vx, vy + k1vy, xt, yt);

    t = t + dt;
    x = x + (k1x + k2x) / 2;
    y = y + (k1y + k2y) / 2;
    vx = vx +(k1vx + k2vx) / 2;
    vy = vy + (k1vy + k2vy) / 2;
}

double TangenteAmilorePlanet (double & t, Planete & planete, Satellite & satellite) {
    M = planete.getM();
    double x = satellite.getX();
    double y = satellite.getY();
    double vx = satellite.getVx();
    double vy = satellite.getVy();

    TangenteAmeliore(gxTa, gyTa, fxTa, fyTa, t, x, y,vx, vy, dt, planete.getX(), planete.getY());

    satellite.setX(x);
    satellite.setY(y);
    satellite.setVx(vx);
    satellite.setVy(vy);

}


