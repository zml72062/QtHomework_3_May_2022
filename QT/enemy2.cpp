#include "enemy2.h"

Enemy2::Enemy2(std::deque<Coordinate>& list,QWidget* parent)
    :EnemyBase(list, parent)
{
    imagePath="./resource/pics/PythonLogo.png";
    speed=0.5;
    totalHealth=20;
    currentHealth=totalHealth;
    rewardTimesTen=10;
}
