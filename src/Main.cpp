#include "../include/Game.h"

// credit: https://www.youtube.com/watch?v=44tO977slsU

Game* game = nullptr;

int main(int argc, char* argv[]) {

    // Calculating delta time and delay for const frame rate
    const int targetFPS = 60;
    const int frameTargetDelay = 1000 / targetFPS;
    Uint32 frameStart;
    Uint32 frameEnd;
    Uint16 deltaTime = 0;
    Uint16 frameTime;

    game = new Game("sdl_test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);

    while (game->running()) {
        frameStart = SDL_GetTicks();

        // Call game methods
        game->handleEvents();
        game->update(deltaTime);
        game->render();

        // Delay next frame
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTargetDelay > frameTime) SDL_Delay(frameTargetDelay - frameTime);

        // Update delta time
        frameEnd = SDL_GetTicks();
        deltaTime = frameEnd - frameStart;
    }

    delete(game);
}
