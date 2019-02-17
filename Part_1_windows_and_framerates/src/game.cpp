#include <game.h>

using namespace std;

game::game(int resolution_x, int resolution_y, string title)
{
    // Initializator

    fps = 60;

    window1 = new RenderWindow(VideoMode(resolution_x,resolution_y),title);

    window1->setFramerateLimit(fps);

    gameLoop();
}


void game::draw()
{

    window1->clear();

    window1->display();
}

void game::gameLoop()
{
    while (window1->isOpen()){
        draw();
    }

}

