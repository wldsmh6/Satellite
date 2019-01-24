#ifndef OBJETSPACIAL_H
#define OBJETSPACIAL_H


class ObjetSpacial {
public:
    ObjetSpacial(double x, double y,double m);
    double distance(ObjetSpacial a);

    inline double getX() {return x;}

    inline double getY() {return y;}


protected :
    double x;
    double y;
    double m;

};

#endif // OBJETSPACIAL_H
