#ifndef SDL_TEST_LINE_H
#define SDL_TEST_LINE_H

#include <SDL.h>
#include <cmath>

class Line {

public:
    Line(SDL_Point p1, SDL_Point p2) : p1(p1), p2(p2) {};
    Line(int x1, int y1, int x2, int y2) : p1{x1, y1}, p2{x2, y2} {};

    double getLength() const;

    SDL_Point getP1() const { return this->p1; };
    void setP1(SDL_Point p) { this->p1 = p; };

    SDL_Point getP2() const { return this->p2; };
    void setP2(SDL_Point p) { this-> p2 = p; };

private:
    SDL_Point p1;
    SDL_Point p2;
};

#endif //SDL_TEST_LINE_H
