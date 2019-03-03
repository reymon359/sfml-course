#include "game.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <stdlib.h>

using namespace sf;
using namespace std;

game::game(Vector2i dimension, std::string title)
{
    window1 = new RenderWindow(VideoMode(dimension.x,dimension.y), title);
    load_resources();
    event = new Event();

    sprite_division.x = 6;
    sprite_division.y = 4;

    gameloop();
}

void game::gameloop()
{

    while(1)
    {
        process_events();
        draw();
    }
}

void game::process_events()
{
    while(window1->pollEvent(*event));
    {
        switch(event->type)
        {

        case Event::Closed:
//        Here was the problem
//            exit(1);
            break;

        }
    }
}

void game::load_resources()
{
    txt_character1 =  new Texture();
    txt_character1->loadFromFile("1.png");
    spr_character1 = new Sprite(*txt_character1);

    txt_enemy1 =  new Texture();
    txt_enemy1->loadFromFile("2.png");
    spr_enemy1 = new Sprite(*txt_enemy1);
    spr_enemy1->setPosition(100,100);

    set_frame(*spr_character1);
    set_frame(*spr_enemy1);
}
void game::draw()
{
    window1->clear();
    window1->draw(*spr_character1);
    window1->draw(*spr_enemy1);
    window1->display();
}
void game::set_frame(Sprite &spr_anyone, Vector2i frame_number){

    // Now we get the original height and width
    // to get the sprites dinamically from the texture
//      IntRect position(frame_number.x,frame_number.y, (float)spr_anyone.getTexture()->getSize().x / (float)sprite_division.x, (float)spr_anyone.getTexture()->getSize().y / (float)sprite_division.y);
         IntRect position(0,0, (float)spr_anyone.getTexture()->getSize().x / 6, (float)spr_anyone.getTexture()->getSize().y / 4);
        spr_anyone.setTextureRect(position);
}
