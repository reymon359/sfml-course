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

    private:

    RenderWindow * window1;
    Event * event;
    Sprite * spr_character1;
    Texture * txt_character1;
};

#endif // GAME_H
