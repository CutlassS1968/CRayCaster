#ifndef SDL_TEST_WORLDSTATE_H
#define SDL_TEST_WORLDSTATE_H

#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include "Wall.h"

class WorldState {
public:
    WorldState(int worldWidth, int worldHeight);

    void addWall(const std::string& key, Wall wall) { wallsMap[key].push_back(wall); };
    void addWallGroup(const std::string& key, std::vector<Wall> walls) { wallsMap[key] = std::move(walls); };

    void draw(SDL_Renderer* renderer);

private:
    std::map<std::string, std::vector<Wall>> wallsMap;
    int worldWidth;
    int worldHeight;
};

#endif //SDL_TEST_WORLDSTATE_H
