#include "../include/Line.h"


double Line::getLength() const {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
