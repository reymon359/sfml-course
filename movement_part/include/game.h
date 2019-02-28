#pragma once

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

using namespace sf;


class game
{
public:
    // Constructor
    game(Vector2f dimension,std::string title);
    void gameloop();


private:

    RenderWindow * window1;
    bool gameover = false;
    float fps;

    // Time
    Clock * clock1;
    Time * time1;
    float  time2;
};

#endif // GAME_H
