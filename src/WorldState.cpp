

#include "../include/WorldState.h"


WorldState::WorldState(const int worldWidth, const int worldHeight) {
    this->worldWidth = worldWidth;
    this->worldHeight = worldHeight;
}

void WorldState::draw(SDL_Renderer *renderer) {
    for (auto & it : wallsMap) {
        for (Wall wall : it.second) {
            SDL_Point p1 = wall.getP1();
            SDL_Point p2 = wall.getP2();
            SDL_Color c = wall.getColor();
            SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
            SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
        }
    }
}


