#include <SFML/Graphics.hpp>
#include <game.h>

using namespace sf;


int main( int argc, char * args[])
{
    game * match1;
    match1 = new game(800, 600,"hello");


    return 0;
}



//// OLD MAIN
//int main( int argc, char * args[])
//{
//
//    //To keep the game open
//    bool gameOver = false;
//
//    // We declare a new window using pointers
//    RenderWindow * window1;
//
//    // Then we initialize it
//    window1 = new RenderWindow(VideoMode(800,600), "Learning sfml");
//
//    // To control the framerate
//    int fps = 60;
//
//    window1->setFramerateLimit(fps);
//
//    while(!gameOver){
//
//        // Clean the window in 1 color
//        window1->clear(Color::Green);
//
//        // To show the window
//        window1->display();
//
//    }
//
//    return 0;
//
//}
