#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>

using namespace sf;

class enemy
{
public:
    // cctor
    enemy();
    Sprite get_sprite();

private:
    Texture txt_monster;
    Sprite spr_monster;
};

#endif // ENEMY_H
