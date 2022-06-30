#include "enemy1.h"

Enemy1::Enemy1(std::deque<Coordinate>& list,QWidget* parent)
    :EnemyBase(list, parent)
{
    type=0;
    imagePath="../QT/resource/pics/C++Logo.png";
    speed=0.07;
    totalHealth=2.0;
    currentHealth=totalHealth;
    rewardTimesTen=10;
}

void Enemy1::beAttacked(int x, int y)
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
        currentHealth-=0.5;
    }
    else if(parent->buttons[x][y]->text()=="CE")
    {
        currentHealth-=2;
    }
    else if(parent->buttons[x][y]->text()=="PE")
    {
        speed-=0.02;
    }
    else if(parent->buttons[x][y]->text()=="RTE")
    {
        currentHealth=0;
    }
    if(currentHealth<0) currentHealth=0;
    if(speed<0) speed=0;
    if(currentHealth<=0.001||speed<=0.001)
    {
//        imagePath="../QT/resource/pics/empty.png";
        emit die(0,x,y);
    }
}
