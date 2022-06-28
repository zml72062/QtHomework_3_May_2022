#include "gamelevel.h"

GameLevel::GameLevel(int mapWidth, int mapHeight,int numOfEnemies, QWidget *parent)
    :QDialog(parent)
{
    this->mapWidth=mapWidth;
    this->mapHeight=mapHeight;
    gameMap=new char*[mapHeight];
    for(int i=0;i<mapHeight;++i)
    {
        gameMap[i]=new char[mapWidth];
    }
    enemyList=new std::deque<Enemy>;
}

GameLevel::~GameLevel()
{
    for(int i=0;i<mapHeight;++i)
    {
        delete[] gameMap[i];
    }
    delete[] gameMap;
    delete enemyList;
}
