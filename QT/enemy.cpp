#include "enemy.h"
#include "iostream"

EnemyBase::EnemyBase(std::deque<Coordinate> &myListOfCoordinates, QWidget *parent)
    :QWidget(parent)
{
    listOfCoordinates=myListOfCoordinates;
    this->parent=dynamic_cast<GameLevel*>(parent);
    position.x=listOfCoordinates.front().x;
    position.y=listOfCoordinates.front().y;
    listOfCoordinates.pop_front();
    direction=findNewDirection();
    connect(this, &EnemyBase::reached, this, &EnemyBase::beAttacked);
    connect(this, &EnemyBase::die, dynamic_cast<GameLevel*>(parent), &GameLevel::clear);
    connect(this, &EnemyBase::reached, dynamic_cast<GameLevel*>(parent), &GameLevel::clearIcon);
}

EnemyBase::~EnemyBase() {}



Coordinate EnemyBase::findNewDirection()//选择敌人接下来的行进方向
{
    if(listOfCoordinates.empty()) return Coordinate(0,0);
    double x_shift=listOfCoordinates.front().x-position.x;
    double y_shift=listOfCoordinates.front().y-position.y;
    double dir_x=0;
    double dir_y=0;
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
        int a=round(position.x);
        int b=round(position.y);
        if(a>=parent->mapHeight)a=parent->mapHeight-1;
        if(a<0) a=0;
        if(b>=parent->mapWidth)b=parent->mapWidth-1;
        if(b<0)b=0;
        if(parent->gameMap[a][b]=='T')
        {
            emit reached(a,b);
        }
        else if(parent->gameMap[a][b]=='E')
        {
            emit attacked();
        }
    }

}
