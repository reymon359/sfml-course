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
    void set_frame(Sprite &spr_anyone, Vector2i frame_number);

    private:

    RenderWindow * window1;
    Event * event;
    Sprite * spr_character1;
    Texture * txt_character1;
    Sprite * spr_enemy1;
    Texture * txt_enemy1;
    Vector2i sprite_division;
};

#endif // GAME_H
