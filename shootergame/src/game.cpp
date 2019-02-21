#include <game.h>
#include "SFML/Graphics.hpp"
#include <iostream>

// to_string patch
#include <string>
#include <sstream>
namespace patch
{
template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}
}
#include <iostream>


using namespace sf;
using namespace std;

game::game(Vector2f dimension, String title)
{
    game_over=false;

    fps = 60;
    window1 = new RenderWindow(VideoMode(dimension.x,dimension.y), title);
    window1->setFramerateLimit(fps);
    window1->setMouseCursorVisible(false);

    event1 = new Event;

    load_graphics();
    gameloop();
}

void game::gameloop()
{

    while(!game_over)
    {
        window1->clear();
        process_events();
        window1->draw(spr_background);

        for(int i = 0; i<3; i++)
        {

            window1->draw(spr_monster[i]);
        }

        window1->draw(spr_peephole);

        window1->display();

    }
}

void game::load_graphics()
{

    std::string path;
    for(int i = 0; i<3; i++)
    {

        path= "monster"+ patch::to_string(i+1)+ ".jpg";
        txt_monster[i].loadFromFile(path);
        spr_monster[i].setTexture(txt_monster[i]);

    }

    txt_background.loadFromFile("background.jpg");
    spr_background.setTexture(txt_background);

    spr_background.setScale(((float)window1->getSize().x/(float)txt_background.getSize().x), ((float)window1->getSize().y/(float)txt_background.getSize().y));


    txt_peephole.loadFromFile("peephole.png");
    spr_peephole.setTexture(txt_peephole);

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
