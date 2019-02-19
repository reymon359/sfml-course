#include <game.h>

#include "SFML/Graphics.hpp"

using namespace sf;

// Constructor
game::game(Vector2i dimension, std::string title)
{
    fps = 60;

    window1 = new RenderWindow(VideoMode(dimension.x, dimension.y), title);

    window1->setFramerateLimit(fps);

    txt1 = new Texture;

    txt1 -> loadFromFile("1.jpeg");

    spr1 = new Sprite(*txt1);

    // We define a new color
    Color color_1(255,255,255,255); // R, G, B, A (opacity)
    Color transparent(255,255,255,150);

    spr1->setColor(color_1);

    txt2 = new Texture;

    txt2 -> loadFromFile("2.jpg");

    spr2 = new Sprite(*txt2);

    spr2->setColor(transparent);

    spr2->setScale(((float)window1->getSize().x/(float)spr2->getTexture()->getSize().x), ((float)window1->getSize().y/(float)spr2->getTexture()->getSize().y));




    gameLoop();
}


void game::gameLoop()
{

    while(window1->isOpen())
    {

        draw();
    }
}

void game::draw()
{

    // We clean the window and then show it
    window1->clear();
    // It is important to load first the background
    window1->draw(*spr1);
    window1->draw(*spr2);

    window1->display();


}
//game::~game()
//{
//    //dtor
//}
