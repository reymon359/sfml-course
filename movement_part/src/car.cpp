#include "car.h"

#include "SFML/Graphics.hpp"
#include <iostream>
#include <stdlib.h>

using namespace sf;
using namespace std;
car::car()
{
    //ctor
    txt_car = new Texture;
    txt_car->loadFromFile("car.png");

    spr_car = new Sprite(*txt_car);

    spr_car->setPosition(400,100);

    speed.x = 0;
    speed.y = 0;

    acceleration.x = 5;
    acceleration.y = 9.81;
}

void car::update(float delta_t){

delta_t /= 10 ;

speed.x += acceleration.x * delta_t;
speed.y += acceleration.y * delta_t;

spr_car->setPosition(spr_car->getPosition().x + speed.x * delta_t, spr_car->getPosition().y + speed.y * delta_t);

}
