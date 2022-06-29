#include "enemy.h"

EnemyBase::EnemyBase(std::deque<Coordinate> &myListOfCoordinates, QWidget *parent)
    :QWidget(parent)
{
    listOfCoordinates=myListOfCoordinates;
    this->parent=dynamic_cast<GameLevel*>(parent);

}

EnemyBase::~EnemyBase() {}

Coordinate EnemyBase::findNewDirection()//选择敌人接下来的行进方向
{
    if(listOfCoordinates.empty()) return Coordinate(0,0);
    int x_shift=listOfCoordinates.front().x-position.x;
    int y_shift=listOfCoordinates.front().y-position.y;
    int dir_x=0;
    int dir_y=0;
    if(x_shift>0) dir_x=1;
    if(x_shift<0) dir_x=-1;
    if(y_shift>0) dir_y=1;
    if(y_shift<0) dir_y=-1;
    return Coordinate(dir_x,dir_y);
}


void EnemyBase::move()//敌人走一步
{
    if(listOfCoordinates.empty()) return;
    if(direction.x>0){
        position.x+=speed;
        if(position.x>listOfCoordinates.front().x){
            position.x=listOfCoordinates.front().x;
        }

    }
    if(direction.x<0){
        position.x-=speed;
        if(position.x<listOfCoordinates.front().x){
            position.x=listOfCoordinates.front().x;
        }

    }
    if(direction.y>0){
        position.y+=speed;
        if(position.y>listOfCoordinates.front().y){
            position.y=listOfCoordinates.front().y;
        }

    }
    if(direction.y<0){
        position.y-=speed;
        if(position.y<listOfCoordinates.front().y){
            position.y=listOfCoordinates.front().y;
        }

    }
    if(position==listOfCoordinates.front())
    {
        listOfCoordinates.pop_front();
        direction=findNewDirection();
        if(parent->gameMap[static_cast<int>(position.x)][static_cast<int>(position.y)]=='T')
        {
            emit reached(static_cast<int>(position.x),static_cast<int>(position.y));
        }
    }

}
