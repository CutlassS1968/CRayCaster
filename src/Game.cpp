#include "../include/Game.h"
#include "../include/Line.h"

Game::Game(const char* title, int xPos, int yPos, int width, int height, int flags) {
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

void Game::update() {

}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    // Start drawing

    SDL_Point p1 = SDL_Point{0, 0};
    SDL_Point p2 = SDL_Point{screenWidth, screenHeight};

    Line l1 = Line(p1, p2);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);

    SDL_Rect rect = SDL_Rect{0, 0, screenWidth/2, screenHeight/2};
    SDL_RenderDrawRect(renderer, &rect);

    // End Drawing
    SDL_RenderPresent(renderer);
}
