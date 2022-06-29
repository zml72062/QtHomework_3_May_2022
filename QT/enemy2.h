#ifndef ENEMY2_H
#define ENEMY2_H
#include "enemy.h"
#include "gamelevel.h"

// Python 型敌人
class Enemy2 : public EnemyBase
{
public:
    Enemy2(std::deque<Coordinate>& list,QWidget* parent=nullptr);
};

#endif // ENEMY2_H
