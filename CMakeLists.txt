cmake_minimum_required(VERSION 3.21)
project(sdl_test)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR C:/libs/SDL/include)
set(SDL2_LIB_DIR C:/libs/SDL/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(sdl_test
        src/Main.cpp
        src/Game.cpp
        include/Game.h src/Line.cpp include/Line.h include/Wall.h)

# These libraries are in SDL/lib/x64
target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
