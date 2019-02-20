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
    void gameLoop();
    void draw();
    void process_events();
    void process_mouse();
    void process_collisions();


private:

    RenderWindow * window1;
    int fps;
    Texture * txt1;
    Sprite * spr1;
    Texture * txt2;
    Sprite * spr2;
    Sprite* spr3;
    Texture * txt3;

    Event * event1;
    Vector2i  mouse_position;
    RectangleShape* box1;
    CircleShape * ball1;


};

#endif // GAME_H
