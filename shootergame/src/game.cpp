#include <game.h>
#include "enemy.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <stdlib.h>

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
            time2 = time1->asSeconds() +2;
//            time2+=5;
            cout << time2 << endl;
            // To randomly create monsters
            int result;
            result = rand()% 100 + 1;

            if(result<30)
            {
                // We dont create monster
                cout << "we dont create monster" << endl;

            }
            else
            {
                // we create an infinite loop that stops when the monster is created

                bool space_avaliable =false;
                // We create monster
                for (int i= 0; i<4; i++)
                {

                    // we first go through the slots and check if their are avaliable
                    if(!slots_monsters[i])
                    {
                        // if ther is one avaliable we put "space_avaliable" to true
                        space_avaliable=true;
                        cout << "there is a space avaliable" << endl;
                        break;
                    }
                }
                if(space_avaliable)
                {
                    // Now we go through the slots randomly checking if it is avaliable
                    while(1)
                    {
                        int result2 = rand() % 3 ;
                        cout << "random number  "<<result2<< endl; // i dont know why but is giving me the same number all time

                        if(!slots_monsters[result2])
                        {
                            // if the slot is false means that it is avaliable so we create the monster inside
                            slots_monsters[result2]=true;
                            monsters[result2] = new enemy({(float)200*result2,(float)300});
                            cout << "slot avaliable, creating monster on "<<200*result2<< endl;

                        }
                        break;

                    }

                }
            }


        }
        check_enemies();
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

        if(lifes<1)
        {
           game_over=true;
        }
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

        case Event::MouseButtonPressed:
            // We pass the position and the size
            cout << "mouse pressed "<< endl;
            FloatRect line(spr_peephole.getPosition(),(Vector2f)(spr_peephole.getTexture()->getSize()));
            cout << "line "<< endl;
            // We cheeck if  the Peephole sprite is inside od one of the enemies sprite
            for (int i= 0; i<4; i++)
            {
                cout << "loop "<<i << endl;
                if(slots_monsters[i])
                {
                    cout << "there are monsters inmonsters["<<i<<"] " << endl;
                    // we get the sprite and check the global bounds to see if there is something
                    if(monsters[i]->get_sprite().getGlobalBounds().intersects(line))
                    {
                        cout << "Sprites interesct" << endl;
                        monsters[i]=NULL;
                    }

                }
            }

            break;
        }
    }

}
void game::check_enemies()
{

    for(int i = 0; i < 4; i++)
    {
        if(monsters[i])
        {
            // If the monster is alive for 5 seconds it disapears and the player loses 1 life
            if(monsters[i]->get_seconds()>5)
            {

                monsters[i]=NULL;
                lifes--;

            }
        }

    }

}
