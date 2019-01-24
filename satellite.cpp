#include "satellite.hpp"

Satellite::Satellite(double x, double y, double vx, double vy, double m, Planete p) :
    ObjetSpacial (x, y, m), vx(vx), vy(vy), forces (p) {}

void Satellite::setX(double newX) {
    x = newX;
}

void Satellite::setY(double newY) {
    y = newY;
}

void Satellite::setVx(double newVx) {
    vx = newVx;
}

void Satellite::setVy(double newVy) {
    vy = newVy;
}

