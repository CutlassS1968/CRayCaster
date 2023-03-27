#ifndef SDL_TEST_GAME_H
#define SDL_TEST_GAME_H
#include <SDL.h>
#include <iostream>

class Game {

public:
    Game(const char* title, int xPos, int yPos, int width, int height, int flags);
    ~Game();

    void handleEvents();
    void update();
    void render();

    bool running() const { return isRunning; };

private:
    bool isRunning{};
    SDL_Window* window{};
    SDL_Renderer* renderer{};

    int screenWidth;
    int screenHeight;

};


#endif //SDL_TEST_GAME_H
