#include "enemy3.h"

Enemy3::Enemy3(std::deque<Coordinate>& list,QWidget* parent)
    :EnemyBase(list, parent)
{
    type=2;
    imagePath="../QT/resource/pics/juanLogo.png";
    speed=0.04;
    totalHealth=10.0;
    currentHealth=totalHealth;
    rewardTimesTen=10;
}

void Enemy3::beAttacked(int x, int y)
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
        emit die(2,x,y);
    }
}
