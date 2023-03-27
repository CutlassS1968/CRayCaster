#ifndef SDL_TEST_WALL_H
#define SDL_TEST_WALL_H

#include "Line.h"

class Wall : public Line {

public:
    Wall(SDL_Point p1, SDL_Point p2, SDL_Color c) : Line(p1, p2), color(c) {};

    SDL_Color getColor() { return color; };
    void setColor(SDL_Color c) { this->color = c; };
    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) { this->color = SDL_Color{r, g, b, a}; };

private:
    SDL_Color color;

};

#endif //SDL_TEST_WALL_H
