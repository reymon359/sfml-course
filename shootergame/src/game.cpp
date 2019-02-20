#include <game.h>
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

game::game(Vector2f dimension, String title)
{
    game_over=false;

    fps = 60;
    window1 = new RenderWindow(VideoMode(dimension.x,dimension.y), title);
    window1->setFramerateLimit(fps);

    gameloop();
}

void game::gameloop()
{

    while(!game_over)
    {
        window1->clear();


        window1->display();

    }
}

void game::load_graphics(){



}
