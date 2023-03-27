#ifndef SDL_TEST_GAME_H
#define SDL_TEST_GAME_H
#include <SDL.h>
#include <iostream>

#include "../include/Game.h"
#include "../include/Line.h"
#include "../include/WorldState.h"
#include "../include/raycaster.h"

class Game {

public:
    Game(const char* title, int xPos, int yPos, int width, int height, int flags);
    ~Game();

    void handleEvents();
    void update(Uint16 deltaTime);
    void render();

    bool running() const { return isRunning; };

private:
    bool isRunning{};
    SDL_Window* window{};
    SDL_Renderer* renderer{};

    int screenWidth;
    int screenHeight;

    WorldState world;
    RayCaster rayCaster;

    static SDL_Color getRandomColor();
};


#endif //SDL_TEST_GAME_H
