#include <game.h>

#include "SFML/Graphics.hpp"

using namespace sf;

// Constructor
game::game(int width, int height, std::string title)
{
    fps = 60;

    window1 = new RenderWindow(VideoMode(width, height), title);

    window1->setFramerateLimit(fps);

    txt_spr =  new  Texture;

    txt_spr->loadFromFile("Buckrogers_Title.png");

    // Create 2 sprites from the same texture
    spr1 = new Sprite(*txt_spr);
    spr2 = new Sprite(*txt_spr);

    // Now we will set the second sprite in a diferent position
    spr2->setPosition(400,300);
    // We are going to set the origin of the sprite in the middle not in the up-left corner
    spr2->setOrigin((float)(spr2->getTexture()->getSize().x / 2), spr2->getTexture()->getSize().y / 2.f);

    // Change the color
    spr2->setColor(Color::Red);

    // Scale the size
    spr2->setScale(100.f/spr2->getTexture()->getSize().x, 50.f/spr2->getTexture()->getSize().y); // desired size / actual size

    // Scale to full window size
    spr1->setScale(((float)window1->getSize().x/(float)spr1->getTexture()->getSize().x), ((float)window1->getSize().y/(float)spr1->getTexture()->getSize().y));

    // Rotate 90 degrees
    spr2->setRotation(90);

    gameLoop();
}


void game::gameLoop()
{

    while(window1->isOpen())
    {
        spr2->setRotation(spr2->getRotation()+3);

        draw();
    }
}

void game::draw()
{

    // We clean the window and then show it
    window1->clear();

    window1->draw(*spr1);
    window1->draw(*spr2);




    window1->display();


}
//game::~game()
//{
//    //dtor
//}
