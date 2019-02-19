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

    event1= new Event,

    gameLoop();
}


void game::gameLoop()
{

    while(window1->isOpen())
    {
        process_mouse();
        process_events();
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

void game::process_events()
{
    while(window1->pollEvent(*event1))
    {
        // We are going to listen the different events
        switch(event1->type)
        {
        // window closed
        case Event::Closed:
            window1->close();
            exit(1);
            break;
        // Key pressed
        case Event::KeyPressed:
            if(Keyboard::isKeyPressed(Keyboard::Up))
            {
                spr1->setPosition(spr1->getPosition().x,spr1->getPosition().y - 2);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Down))
            {

                spr1->setPosition(spr1->getPosition().x,spr1->getPosition().y + 2);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                spr1->setPosition(spr1->getPosition().x - 2,spr1->getPosition().y);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                spr1->setPosition(spr1->getPosition().x + 2,spr1->getPosition().y);
            }

            break;
        }
    }

}

void game::process_mouse(){
// We need to create first a position mouse because the mouse in in the
// full window, the one the game is included into
    mouse_position = Mouse::getPosition(*window1);
    mouse_position = (Vector2i)window1->mapPixelToCoords(mouse_position);



}
//game::~game()
//{
//    //dtor
//}
