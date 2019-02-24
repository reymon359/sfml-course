#include <game.h>
#include "enemy.h"
#include "SFML/Graphics.hpp"
#include <iostream>


#include <iostream>


using namespace sf;
using namespace std;

game::game(Vector2f dimension, std::string title)
{
    game_over=false;

    fps = 60;

    window1 = new RenderWindow(VideoMode(dimension.x,dimension.y), title);
    window1->setFramerateLimit(fps);
    window1->setMouseCursorVisible(false);


    for (int i= 0; i<4; i++)
    {
        slots_monsters[i]=false;
    }


    event1 = new Event;

    load_graphics();

    clock1 = new Clock();
    time1 = new Time();
    time2 = 5;

    gameloop();
}

void game::gameloop()
{


    while(!game_over)

    {

        *time1 = clock1->getElapsedTime();


        if(time1->asSeconds() > time2)
        {
            time2 = time1->asSeconds() +5;
//            time2+=5;
             cout << time2 << endl;
            // To randomly create monsters
            int result;
            result = rand()% 100 + 1;

            if(result<30)
            {
                // We dont create monster

            }
            else
            {
                // We create monster
                for (int i= 0; i<4; i++)
                {
                    if(!slots_monsters[i])
                    {
                        slots_monsters[i] = true;
                        monsters[i] = new enemy();
                    }

                }
            }


        }
        window1->clear();
        process_events();
        window1->draw(spr_background);

        for (int i= 0; i<4; i++)
        {
            if(slots_monsters[i])
            {
            window1->draw(monsters[i]->get_sprite());
            }
    }


        window1->draw(spr_peephole);

        window1->display();


    }
}

void game::load_graphics()
{

    txt_background.loadFromFile("background.jpg");
    spr_background.setTexture(txt_background);

    spr_background.setScale(((float)window1->getSize().x/(float)txt_background.getSize().x), ((float)window1->getSize().y/(float)txt_background.getSize().y));


    txt_peephole.loadFromFile("peephole.png");
    spr_peephole.setTexture(txt_peephole);
    spr_peephole.setScale((40/(float)txt_peephole.getSize().x), (40/(float)txt_peephole.getSize().y));

}

void game::process_events()
{

    while(window1->pollEvent(*event1))
    {

        switch(event1->type)
        {

        case Event::MouseMoved:
            spr_peephole.setPosition((Vector2f)Mouse::getPosition(*window1));
            break;

        case Event::Closed:
            exit(1);
            break;
        }


    }


}
