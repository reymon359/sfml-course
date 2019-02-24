#include "enemy.h"
#include <stdlib.h>
#include <iostream>
#include "SFML/Graphics.hpp"


using namespace std;
enemy::enemy()
{
//        srand(time(NULL)); For random random
    int enemy_number;

    enemy_number = rand() % 4 + 0; // random between 1 and 3

    std::string path;

    path= "monster"+ std::to_string(enemy_number)+ ".jpg";
    txt_monster.loadFromFile(path);
    spr_monster.setTexture(txt_monster);


}

Sprite enemy::get_sprite()
{

    return spr_monster;
}

