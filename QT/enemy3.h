#ifndef ENEMY3_H
#define ENEMY3_H
#include "enemy.h"
#include "gamelevel.h"

// 卷 型敌人
class Enemy3 : public EnemyBase
{
public:
    Enemy3(std::deque<Coordinate>& list,QWidget* parent=nullptr);
public slots:
    virtual void beAttacked(int,int);
};

#endif // ENEMY3_H
