#ifndef ENEMY_H
#define ENEMY_H

#include <deque>
#include <QString>
#include <QWidget>
#include "gamelevel.h"
#include "mybutton.h"
#include "util.h"
class GameLevel;

//敌人基类
class EnemyBase: public QWidget
{
    Q_OBJECT

public:
    EnemyBase(std::deque<Coordinate>& myListOfCoordinates, QWidget* parent=nullptr);
    virtual ~EnemyBase();
    void move();
    int type;
    int totalHealth;
    int currentHealth;
    double speed; // how many blocks
    int rewardTimesTen;
    int imageHeight;
    int imageWidth;
    const int xOffset=-10;
    const int yOffset=-10;
    Coordinate position;
    Coordinate direction;
    QString imagePath;
    std::deque<Coordinate> listOfCoordinates;
    GameLevel* parent;

signals:
    void reached(int, int);
    void attacked(int,int);
    void die(int,int,int);
public slots:
    virtual void beAttacked(int,int)=0;

private:
    Coordinate findNewDirection();
public:
    Coordinate toBlock(int x,int y) const
    {
        return Coordinate((x-parent->startX())/parent->effWidth(),(y-parent->startY())/parent->effHeight());
    }
    int xPixel(Coordinate coor) const
    {
        return coor.y*parent->effWidth()+parent->startX();
    }
    int yPixel(Coordinate coor) const
    {
        return coor.x*parent->effHeight()+parent->startY();
    }
};

#endif // ENEMY_H
