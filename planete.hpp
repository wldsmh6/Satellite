#ifndef PLANETE_H
#define PLANETE_H

#include "objetspacial.hpp"
#include <Cmath>

class Planete : public ObjetSpacial {
public:
    Planete(double x, double y, double m, double rayon, double rayonTrajectoire, double vitesse);

    inline void setX(double newX) {x = newX;}

    inline void setY(double newY) {y = newY;}

    inline double getM() {return m;}

    inline double getR() {return rayon;}

    inline double getRayonTrajectoire() {return rayonTrajectoire;}

//    void orbite(double dt);

private :
    double rayon;
    double rayonTrajectoire;
    double vitesse;
};

#endif // PLANET_H
