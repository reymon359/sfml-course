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
    spr3 = new Sprite(*txt2);
    spr3->setColor(Color::Blue);
    spr3->setPosition(window1->getSize().x/2.f, window1->getSize().y/2.f);

    spr2->setColor(transparent);
    // Full window
    // spr2->setScale(((float)window1->getSize().x/(float)spr2->getTexture()->getSize().x), ((float)window1->getSize().y/(float)spr2->getTexture()->getSize().y));
    spr2->setScale((50/(float)spr2->getTexture()->getSize().x), (50/(float)spr2->getTexture()->getSize().y));

    event1= new Event,

    gameLoop();
}


void game::gameLoop()
{

    while(window1->isOpen())
    {
        process_mouse();
        process_events();
        process_collisions();
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
    window1->draw(*spr3);
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
                spr2->setPosition(spr2->getPosition().x,spr2->getPosition().y - 5);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Down))
            {

                spr2->setPosition(spr2->getPosition().x,spr2->getPosition().y + 5);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                spr2->setPosition(spr2->getPosition().x - 5,spr2->getPosition().y);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                spr2->setPosition(spr2->getPosition().x + 5,spr2->getPosition().y);
            }

            break;

        case Event::MouseButtonPressed:


            if(Mouse::isButtonPressed(Mouse::Left))
            {

                // To move sprite to mouse position
                // spr1->setPosition(Vector2f(mouse_position));
                if(mouse_position==(Vector2i)spr2->getPosition())
                {
                    spr2->setColor(Color::Red);
                }
                break;
            }
        }

    }
}

void game::process_mouse()
{
// We need to create first a position mouse because the mouse in in the
// full window, the one the game is included into
    mouse_position = Mouse::getPosition(*window1);
    mouse_position = (Vector2i)window1->mapPixelToCoords(mouse_position);

}

void game::process_collisions()
{

    //  We will create a rectangle in the mouse position
    FloatRect rectangle_on_mouse(Vector2f(mouse_position), {32,32});

    if(spr2->getGlobalBounds().intersects(rectangle_on_mouse))
    {
        spr2->setPosition(Vector2f(mouse_position));
    }
    // If spr2 colisions with spr3 it rotates 3 degrees
    if(spr2->getGlobalBounds().intersects(spr3->getGlobalBounds())){
        spr3->rotate(3);
        spr3->setColor(Color::Green);
    }
}


//game::~game()
//{
//    //dtor
//}
