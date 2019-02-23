#pragma once
#ifndef GAME_H
#pragma once
#define GAME_H
#include "enemy.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class game
{
public:
    // Constructor
    game(Vector2f dimension, String title);
    void gameloop();
    void load_graphics();
    void process_events();

private:

    int fps;
    RenderWindow * window1;
// Now in enemy class
//    Texture txt_monster[3];
//    Sprite spr_monster[3];

    Texture txt_background;
    Sprite spr_background;

    Texture txt_peephole;
    Sprite spr_peephole;

    Event * event1;

    enemy * monsters[4];

    bool game_over;
    bool slots_monsters[4];

};

#endif // GAME_H
