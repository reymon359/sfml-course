#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

using namespace std;


int main(int argc, char *args[])
{

    bool game_over = false;

    RenderWindow window(VideoMode(800,600,32),"Example");

    while (!game_over)
    {

        window.display();
    }

    return 0;
}

