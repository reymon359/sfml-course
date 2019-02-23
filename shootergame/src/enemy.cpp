#include "enemy.h"
#include <stdlib.h>



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
enemy::enemy()
{
cout<< "hola";
//        srand(time(NULL)); For random random
    int enemy_number;

    enemy_number = rand() % 3 + 1; // random between 1 and 3

    std::string path;

    path= "monster"+ patch::to_string(enemy_number)+ ".jpg";
    txt_monster.loadFromFile(path);
    spr_monster.setTexture(txt_monster);
    cout<< path;

}

Sprite enemy::get_sprite()
{

    return spr_monster;
}

