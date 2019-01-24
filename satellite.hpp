#ifndef SATELLITE_H
#define SATELLITE_H

#include <objetspacial.hpp>
#include <vector>
#include <planete.hpp>
#include <string>
#include <cmath>

using namespace std;

class Satellite : public ObjetSpacial {
public:
    Satellite(double x, double y, double vx, double vy, double m, Planete p);

    inline double getVx() {return vx;}

    inline double getVy() {return vy;}

    void setX(double newX);

    void setY(double newY);

    void setVx(double newVx);

    void setVy(double newVy);

private :
    double vx;
    double vy;
    Planete forces;
};

#endif // SATELLITE_H
