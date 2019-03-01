
#pragma once

#ifndef CAR_H
#define CAR_H

#include <SFML/Graphics.hpp>

using namespace sf;
class car
{
public:
    // Constructor
    car();
    void update(float delta_t);
    Sprite get_sprite()
    {
        return * spr_car;
    };


private:

    Sprite * spr_car;
    Texture * txt_car;
    Vector2f speed;
    Vector2f acceleration;


};
#endif // CAR_H
