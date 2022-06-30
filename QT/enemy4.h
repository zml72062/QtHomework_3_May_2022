#ifndef ENEMY4_H
#define ENEMY4_H
#include "enemy.h"
#include "gamelevel.h"

// 菜 型敌人
class Enemy4 : public EnemyBase
{
public:
    Enemy4(std::deque<Coordinate>& list,QWidget* parent=nullptr);
public slots:
    virtual void beAttacked(int,int);
};

#endif // ENEMY4_H
