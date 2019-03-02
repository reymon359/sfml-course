#pragma once

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

using namespace sf;

class game
{
public:
    // Constructor
    game(Vector2i dimension, std::string title);

    void gameloop();
    void process_events();
    void load_resources();
    void draw();
    void set_frame(sprite);

    private:

    RenderWindow * window1;
    Event * event;
    Sprite * spr_character1;
    Texture * txt_character1;
    Sprite * spr_enemy1;
    Texture * txt_enemy1;
};

#endif // GAME_H
