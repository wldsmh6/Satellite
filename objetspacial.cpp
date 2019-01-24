#include "objetspacial.hpp"
#include <cmath>

ObjetSpacial::ObjetSpacial(double x, double y, double m) : x(x), y(y), m(m) {}


double ObjetSpacial::distance (ObjetSpacial a){
    return ( sqrt ((x - a.x )*(x - a.x ) + (y - a.y )*(y - a.y ) ) ) ;
}
