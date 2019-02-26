#pragma once

#ifndef GAME_H
#define GAME_H

#include "enemy.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class game
{
public:
    // Constructor
    game(Vector2f dimension, std::string title);

    void gameloop();
    void load_graphics();
    void process_events();
    void check_enemies();

private:

    RenderWindow * window1;

    int lifes = 3;

    Texture txt_background;
    Sprite spr_background;

    Texture txt_peephole;
    Sprite spr_peephole;



    enemy * monsters[4];


     // Time
    Clock * clock1;
    Time * time1;
    float  time2;

Event * event1;

    bool game_over;
    bool slots_monsters[4];
    int fps;
};

#endif // GAME_H
