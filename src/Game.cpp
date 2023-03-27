#include <ctime>
#include "../include/Game.h"
#include "../include/raycaster.h"

Game::Game(const char* title, int xPos, int yPos, int width, int height, int flags) :
world(width, height),
rayCaster(width, height, width/2, height/2){
    isRunning = true;
    screenWidth = width;
    screenHeight = height;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "[ERROR] %s" << SDL_GetError() << std::endl;
        isRunning = false;
    } else {
        std::cout << "[LOG] Subsystems initialized" << std::endl;

        // Create window
        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
        if (!window) {
            std::cout << "[ERROR] %s" << SDL_GetError() << std::endl;
            isRunning = false;
        } else {
            std::cout << "[LOG] Window created" << std::endl;
        }

        // Create renderer
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (!renderer) {
            std::cout << "[ERROR] %s" << SDL_GetError() << std::endl;
            isRunning = false;
        } else {
            std::cout << "[LOG] Renderer created" << std::endl;
        }
    }

    std::vector<Wall> walls;
    int xOffset = screenWidth / 2;
    int yOffset = screenHeight / 2;
    walls.emplace_back(SDL_Point{xOffset + 0, yOffset + 0}, SDL_Point{xOffset + 10, yOffset + 0}, getRandomColor());
    walls.emplace_back(SDL_Point{xOffset + 10, yOffset + 0}, SDL_Point{xOffset + 10, yOffset + 10}, getRandomColor());
    walls.emplace_back(SDL_Point{xOffset + 10, yOffset + 10}, SDL_Point{xOffset + 0, yOffset + 10}, getRandomColor());
    walls.emplace_back(SDL_Point{xOffset + 0, yOffset + 10}, SDL_Point{xOffset + 0, yOffset + 0}, getRandomColor());
    world.addWallGroup("default", walls);
}

Game::~Game() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "[LOG] Game cleaned" << std::endl;
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update(Uint16 deltaTime) {
    rayCaster.update(deltaTime);
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    world.draw(renderer);
    rayCaster.draw(renderer);
    SDL_RenderPresent(renderer);
}

SDL_Color Game::getRandomColor() {
    return SDL_Color{ static_cast<Uint8>(std::rand() % 256),
                      static_cast<Uint8>(std::rand() % 256),
                      static_cast<Uint8>(std::rand() % 256), 255 };
}
