#ifndef UTIL_H
#define UTIL_H

#include <deque>

struct Enemy
{
    int x;
    int y;
    double speed;
    int blood;
};

struct Tower
{
    int x;
    int y;
    double cd;
};

struct Bullet
{
    int startx;
    int starty;

    int angle; // -180 ~ 180
    double speed;
};

#endif // UTIL_H
