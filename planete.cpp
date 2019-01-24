#include "planete.hpp"

Planete::Planete(double x, double y, double m, double rayon, double rayonTrajectoire,
                 double vitesse ) : ObjetSpacial (x,y,m), rayon (rayon),
    rayonTrajectoire (rayonTrajectoire), vitesse(vitesse){}


//void Planete::orbite (double dt) {
//    static double t = 0;
//    static const double T = (2 * M_PI * rayonTrajectoire)/vitesse;

//    if (t > T - dt) {
//        t = t + dt - T;
//    }
//    else {
//        t = t + dt;
//    }

//    x = rayonTrajectoire * cos ((t * vitesse) / rayonTrajectoire);
//    y = rayonTrajectoire * sin ((t * vitesse) / rayonTrajectoire);

//}
