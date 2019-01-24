#include "RungeKutta.hpp"


static double const G = 6.67408e-11;  //constante gravitationelle
static double M; //masse de la terre
static double const dt = 10;    //pas de temps

double fx(double t, double x, double y, double vx, double vy, double xt, double yt)  //derivee seconde en x
{
    double r2;
    r2 = (x-xt)*(x-xt) + (y-yt)*(y-yt);
    double r = sqrt(r2);
    double res = -G*M*(x - xt);
    res /= r;
    res /= r2;
    return res;
}


double fy(double t, double x, double y, double vx, double vy, double xt, double yt)  //derivee seconde en y
{
    double r2;
    r2 = (x-xt)*(x-xt) + (y-yt)*(y-yt);
    double r = sqrt(r2);
    double res = -G*M*(y - yt);
    res /= r;
    res /= r2;
    return res;
}

double gx(double t, double x, double y, double vx, double vy, double xt, double yt) //vitesse en x
{
    return vx;
}

double gy(double t, double x, double y, double vx, double vy, double xt, double yt)  //vitesse en y
{
    return vy;
}


void RK(double(*g1)(double t, double x, double y, double vx, double vy, double xt, double yt),
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
    {
        double k11 = g1(t, x, y, vx, vy, xt, yt); //gx x
        double k12 = g2(t, x, y, vx, vy, xt, yt); //gy y
        double k13 = g3(t, x, y, vx, vy, xt, yt); //fx vx
        double k14 = g4(t, x, y, vx, vy, xt, yt); //fy vy

        double k21 = g1(t + dt / 2, x + (dt / 2) * k11, y + (dt / 2) * k12, vx + (dt / 2) * k13, vy + (dt / 2) * k14, xt, yt);
        double k22 = g2(t + dt / 2, x + (dt / 2) * k11, y + (dt / 2) * k12, vx + (dt / 2) * k13, vy + (dt / 2) * k14, xt, yt);
        double k23 = g3(t + dt / 2, x + (dt / 2) * k11, y + (dt / 2) * k12, vx + (dt / 2) * k13, vy + (dt / 2) * k14, xt, yt);
        double k24 = g4(t + dt / 2, x + (dt / 2) * k11, y + (dt / 2) * k12, vx + (dt / 2) * k13, vy + (dt / 2) * k14, xt, yt);

        double k31 = g1(t + dt, x + dt*k21, y + dt*k22, vx + dt*k23, vy + dt*k24, xt, yt);
        double k32 = g2(t + dt, x + dt*k21, y + dt*k22, vx + dt*k23, vy + dt*k24, xt, yt);
        double k33 = g3(t + dt, x + dt*k21, y + dt*k22, vx + dt*k23, vy + dt*k24, xt, yt);
        double k34 = g4(t + dt, x + dt*k21, y + dt*k22, vx + dt*k23, vy + dt*k24, xt, yt);


        t = t + dt;
        x = x + (dt / 6) * (k11 + 4 * k21 + k31);
        y = y + (dt / 6) * (k12 + 4 * k22 + k32);
        vx = vx + (dt / 6) * (k13 + 4 * k23 + k33);
        vy = vy + (dt / 6) * (k14 + 4 * k24 + k34);
    }
}


double RKPlanet (double & t, Planete & planete, Satellite & satellite) {
    M = planete.getM();
    //planete.orbite(dt);
    double x = satellite.getX();
    double y = satellite.getY();
    double vx = satellite.getVx();
    double vy = satellite.getVy();

    RK(gx, gy, fx, fy, t, x, y,vx, vy, dt, planete.getX(), planete.getY());

    satellite.setX(x);
    satellite.setY(y);
    satellite.setVx(vx);
    satellite.setVy(vy);

}
