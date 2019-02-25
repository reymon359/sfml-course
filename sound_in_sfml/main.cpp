#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
    RenderWindow window(VideoMode(800,600). "sound tutorial");

    // the soundbuffer has the sound file (like the texture)
    SoundBuffer buffer;
    // The sound loads the buffer (like the sprite loads the texture)
    Sound sound;

{

