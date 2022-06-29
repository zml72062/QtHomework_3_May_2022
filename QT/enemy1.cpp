#include "enemy1.h"

Enemy1::Enemy1(std::deque<Coordinate>& list,QWidget* parent)
    :EnemyBase(list, parent)
{
    imagePath="./resource/pics/C++Logo.png";
    speed=1;
    totalHealth=10;
    currentHealth=totalHealth;
    rewardTimesTen=10;
}
