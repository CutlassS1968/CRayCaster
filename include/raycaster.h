#ifndef SDL_TEST_RAYCASTER_H
#define SDL_TEST_RAYCASTER_H

#include <SDL.h>
#include <vector>
#include <cmath>
#include "Ray.h"

class RayCaster {
public:
    RayCaster(int width,  int height, int xPos, int yPos);
    ~RayCaster();

    void genRays();
    void updateRays();
    void updateCone();

    void handleEvents();
    void update(Uint16 deltaTime);
    void draw(SDL_Renderer* renderer);

private:
    const int FOV = 100;
    const float rotationDelta = (90 * ((float)M_PI / 180)) - ((float)FOV / 2);
    const float rotationUnits = 1 * ((float)M_PI / 180);
    const int viewRadius = 100;
    const int lightDistance = 100;
    const int resolutionScale = 10;

    int width;
    int height;
    int rayCount;

    SDL_Point position{};

    std::vector<Ray> allRays;
    std::vector<Ray> coneRays;

    Ray fovCenterRay;

    static SDL_Color getRandomColor();

};

#endif //SDL_TEST_RAYCASTER_H
