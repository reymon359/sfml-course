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


 for (int i= 0; i<4; i++)
    {
    cout << i;
        slots_monsters[i]=NULL;
//         cout << line slots_monsters[i];
    }


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


        for (int i= 0; i<4; i++)
        {
          if(monsters[i] != NULL){

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
