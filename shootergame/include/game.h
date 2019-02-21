#pragma once
#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

using namespace sf;

class game
{
public:
    // Constructor
    game(Vector2f dimension, String title);
    void gameloop();
    void load_graphics();

private:

    int fps;
    RenderWindow * window1;

    Texture txt_monster[3];
    Sprite spr_monster[3];

    Texture txt_background;
    Sprite spr_background;

    Texture txt_peephole;
    Sprite spr_peephole;

    bool game_over;

};

#endif // GAME_H
