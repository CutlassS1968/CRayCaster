#ifndef SDL_TEST_RAY_H
#define SDL_TEST_RAY_H

#include "Line.h"

class Ray : public Line {

public:

    Ray() : Line(SDL_Point{}, SDL_Point{}), color(SDL_Color{}), rd(0) {};

    Ray(SDL_Point p1, SDL_Point p2, SDL_Color c, float rd) : Line(p1, p2), color(c), rd(rd) {};

    SDL_Color getColor() { return color; };
    void setColor(SDL_Color c) { this->color = c; };
    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) { this->color = SDL_Color{r, g, b, a}; };

    void setRD(float d) { this->rd = d; };
    float getRD() const { return rd; };

private:
    SDL_Color color;
    float rd = rd;

};

#endif //SDL_TEST_RAY_H
