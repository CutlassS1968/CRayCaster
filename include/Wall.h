#ifndef SDL_TEST_WALL_H
#define SDL_TEST_WALL_H

#include "Line.h"

class Wall : public Line {

public:
    Wall(SDL_Point p1, SDL_Point p2, SDL_Color c) : Line(p1, p2), color(c) {};

private:
    SDL_Color color;

};

#endif //SDL_TEST_WALL_H
