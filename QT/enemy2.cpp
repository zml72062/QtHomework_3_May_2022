#include "enemy2.h"

Enemy2::Enemy2(std::deque<Coordinate>& list,QWidget* parent)
    :EnemyBase(list, parent)
{
    imagePath="../QT/resource/pics/PythonLogo.png";
    speed=0.05;
    totalHealth=20;
    currentHealth=totalHealth;
    rewardTimesTen=10;
}
