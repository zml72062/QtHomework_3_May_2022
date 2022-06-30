#include "enemy4.h"

Enemy4::Enemy4(std::deque<Coordinate>& list,QWidget* parent)
    :EnemyBase(list, parent)
{
    type=3;
    imagePath="../QT/resource/pics/caiLogo.png";
    speed=0.05;
    totalHealth=2.0;
    currentHealth=totalHealth;
    rewardTimesTen=20;
}

void Enemy4::beAttacked(int x, int y)
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
        currentHealth-=1;
    }
    else if(parent->buttons[x][y]->text()=="CE")
    {
        currentHealth-=1;
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
        emit die(3,x,y);
    }
}
