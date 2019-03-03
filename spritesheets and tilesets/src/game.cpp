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

    actual_frame.x = 0;
    actual_frame.y = 0;

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
        case Event::KeyPressed:
            if(Keyboard::isKeyPressed(Keyboard::A))
            {

                if(actual_frame.x < sprite_division.x -1)
                    actual_frame.x++;
                set_frame(*spr_character1,actual_frame);

            }
            else if(Keyboard::isKeyPressed(Keyboard::D))
            {
                if(actual_frame.y < sprite_division.y -1)
                    actual_frame.y++;
                set_frame(*spr_character1,actual_frame);
            }
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

    set_frame(*spr_character1, {0,1});
    set_frame(*spr_enemy1, {2,2});
}
void game::draw()
{
    window1->clear();

    if(actual_frame.x < sprite_division.x -1)
        actual_frame.x++;
    else
        actual_frame.x = 0;

    set_frame(*spr_character1, actual_frame);

    window1->draw(*spr_character1);
    window1->draw(*spr_enemy1);
    window1->display();
}
void game::set_frame(Sprite &spr_anyone, Vector2i frame_number)
{

    // Now we get the original height and width
    // to get the sprites dinamically from the texture
    IntRect position((float)frame_number.x * (float)(spr_anyone.getTexture()->getSize().x / (float)sprite_division.x),(float)frame_number.y * (float)(spr_anyone.getTexture()->getSize().y / (float)sprite_division.y),
                     (float)spr_anyone.getTexture()->getSize().x / sprite_division.x, (float)spr_anyone.getTexture()->getSize().y / (float)sprite_division.y);
    spr_anyone.setTextureRect(position);
}
