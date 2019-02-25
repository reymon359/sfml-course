#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(800,600),"sound tutorial");

    // the soundbuffer has the sound file (like the texture)
    SoundBuffer buffer;
    // The sound loads the buffer (like the sprite loads the texture)
    Sound sound;

    if(!buffer.loadFromFile("1.wav"))
    {
        cout<<"Could not be loaded"<<endl;

    }
    // Now we have the sound and can work with it
    sound.setBuffer(buffer);

    while(window.isOpen())
    {

        // Controll events
        Event event;

        while (window.pollEvent(event))
        {
            // CLose window
            if(event.type == Event::Closed)
            {
                window.close();
            }

            // Mouse button makes a sound
            if(event.type==Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == Mouse::Button::Left)
                {
                sound.setVolume(65);
                    cout<<"sound 1";
                    sound.play();
                }


            }


        }
        window.clear();
        window.display();
    }
    return 0;
}

