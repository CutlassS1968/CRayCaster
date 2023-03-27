#include <iostream>
#include "../include/raycaster.h"


RayCaster::RayCaster(int w, int h, int xPos, int yPos) {
    position = SDL_Point{xPos, yPos};
    width = w;
    height = h;
    rayCount = (int)((width / (FOV / (360 * (M_PI / 180)))) / resolutionScale);
    std::cout << rayCount << std::endl;
    genRays();

    SDL_Point p1 = position;
    int x = p1.x + (viewRadius * std::cos(((float)FOV / 2) + rotationDelta));
    int y = p1.y + (viewRadius * std::sin(((float)FOV / 2) + rotationDelta));
    SDL_Point p2 = SDL_Point{ x, y };
    SDL_Color c = SDL_Color{ 255, 255, 255 };
    fovCenterRay = Ray(p1, p2, c, 0);
}

RayCaster::~RayCaster() = default;

void RayCaster::genRays() {
    auto radSlice = (float)((360.0 / rayCount) * (M_PI / 180));
    SDL_Point p1 = position;
    for (int i = 0; i < rayCount; i++) {
        int x = (p1.x + (viewRadius * cos(radSlice * i)));
        int y = (p1.y + (viewRadius * sin(radSlice * i)));
        SDL_Point p2 = SDL_Point{ x, y };
        allRays.emplace_back(Ray(p1, p2, getRandomColor(), radSlice * i));
    }
}

void RayCaster::updateRays() {
    auto radSlice = (float)((360.0 / rayCount) * (M_PI / 180));
    SDL_Point p1 = position;
    for (int i = 0; i < rayCount; i++) {
        int x = (p1.x + (viewRadius * cos(radSlice * i)));
        int y = (p1.y + (viewRadius * sin(radSlice * i)));
        SDL_Point p2 = SDL_Point{ x, y };
        allRays[i].setP1(p1);
        allRays[i].setP2(p2);
    }
}

void RayCaster::updateCone() {
    coneRays.clear();
    float fovLower = rotationDelta;
    float fovUpper = rotationDelta + (float)FOV;

    if (fovUpper > (360 * (M_PI / 180))) {
        fovUpper = (rotationDelta + FOV) - (360 * (M_PI / 180));
    }

    SDL_Point p1 = position;
    int x = p1.x + (viewRadius * std::cos(((float)FOV / 2) + rotationDelta));
    int y = p1.y + (viewRadius * std::sin(((float)FOV / 2) + rotationDelta));
    SDL_Point p2 = SDL_Point{ x, y };
    fovCenterRay.setP1(p1);
    fovCenterRay.setP2(p2);
    fovCenterRay.setRD((FOV / 2) + rotationDelta);

    if (fovUpper > fovLower) {
        for (int i = 0; i < rayCount; i++) {
            float rd = allRays[i].getRD();
            if (fovLower <= rd && rd <= fovUpper) {
                // TODO: reference or copy? should be copy... maybe?
                coneRays.push_back(allRays[i]);
            }
        }
    }
    if (fovLower > fovUpper) {
        for (int i = 0; i < rayCount; i++) {
            float rd = allRays[i].getRD();
            if (fovLower < rd && rd < (360 * (M_PI / 180))) {
                coneRays.push_back(allRays[i]);
            }
        }
        for (int i = 0; i < rayCount; i++) {
            float rd = allRays[i].getRD();
            if (rd < fovLower && rd < fovUpper) {
                coneRays.push_back(allRays[i]);
            }
        }
    }

}

SDL_Color RayCaster::getRandomColor() {
    return SDL_Color{ static_cast<Uint8>(std::rand() % 256),
                      static_cast<Uint8>(std::rand() % 256),
                      static_cast<Uint8>(std::rand() % 256), 255 };
}

void RayCaster::handleEvents() {

}

void RayCaster::update(Uint16 deltaTime) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    position = SDL_Point{ x, y };
    updateRays();
    updateCone();
}

void RayCaster::draw(SDL_Renderer* renderer) {
    for (Ray ray : coneRays) {
        SDL_Point p1 = ray.getP1();
        SDL_Point p2 = ray.getP2();
        SDL_Color c = ray.getColor();
        SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
        SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
    }
}
