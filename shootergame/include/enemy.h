#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "SFML/Graphics.hpp"

using namespace sf;

class enemy
{
public:
    // cctor
    enemy(Vector2f position);
    Sprite get_sprite();
    float get_seconds();

private:
    Texture txt_monster;
    Sprite spr_monster;

    Clock * clock1;
    Time * time1;
};

#endif // ENEMY_H
