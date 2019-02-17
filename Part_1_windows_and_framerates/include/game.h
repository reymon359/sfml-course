#pragma once
#define GAME_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class game
{
public:

    // Class constructor
    game(int resolution_x, int resolution_y, string title);

    // To display de window
    void draw();

    // Loop that repeats always
    void gameLoop();


private:

    RenderWindow * window1;

    int fps;
};


