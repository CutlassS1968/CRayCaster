#include "../include/Game.h"

// credit: https://www.youtube.com/watch?v=44tO977slsU

Game* game = nullptr;

int main(int argc, char* argv[]) {
    game = new Game("sdl_test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    delete(game);
}
