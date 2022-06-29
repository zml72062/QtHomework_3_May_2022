#ifndef ENEMY1_H
#define ENEMY1_H
#include "enemy.h"
#include "gamelevel.h"

// C 型敌人
class Enemy1 : public EnemyBase
{
public:
    Enemy1(std::deque<Coordinate>& list,QWidget* parent=nullptr);
public slots:
    virtual void beAttacked(int,int);
};

#endif // ENEMY1_H
