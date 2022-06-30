#include "enemy2.h"

Enemy2::Enemy2(std::deque<Coordinate>& list,QWidget* parent)
    :EnemyBase(list, parent)
{
    type=1;
    imagePath="../QT/resource/pics/PythonLogo.png";
    speed=0.05;
    totalHealth=4.0;
    currentHealth=totalHealth;
    rewardTimesTen=10;
}

void Enemy2::beAttacked(int x, int y)
{
    if(parent->buttons[x][y]->text()=="T")
    {
        return;
    }
    else if(parent->buttons[x][y]->text()=="WA")
    {
        currentHealth-=1;
    }
    else if(parent->buttons[x][y]->text()=="TLE")
    {
        currentHealth-=2;
    }
    else if(parent->buttons[x][y]->text()=="CE")
    {
        currentHealth-=0.5;
    }
    else if(parent->buttons[x][y]->text()=="PE")
    {
        speed-=0.02;
    }
    if(currentHealth<0) currentHealth=0;
    if(speed<0) speed=0;
    if(currentHealth<=0.001||speed<=0.001)
    {
//        imagePath="../QT/resource/pics/empty.png";
        emit die(1,x,y);
    }
}
