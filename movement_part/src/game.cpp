#include <game.h>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <stdlib.h>

using namespace sf;
using namespace std;

game::game(Vector2f dimension, std::string title)
{



    window1 = new RenderWindow(VideoMode(dimension.x,dimension.y), title);
    window1->setFramerateLimit(60);

    fps = 1/60.f;

    clock1 = new Clock();
    time1 = new Time();
    time2 = 0.f;



    gameloop();
}

void game::gameloop()
{
    while(!gameover)
    {

        *time1 = clock1->getElapsedTime();
        if(time1->asSeconds() > time2 + fps)
        {
            time2 = time1->asSeconds();

                    window1->clear();

                     window1->display();
        }
    }



}
