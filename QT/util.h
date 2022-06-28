#ifndef UTIL_H
#define UTIL_H

#include <deque>
#include <math.h>

struct Enemy
{
    int x;
    int y;
    double speed;
    double blood;
};

inline std::deque<int> GPAToColor(double GPA)
{
    int score=100-sqrt((4-GPA)*1600.0/3.0);
    if(score>=80)
    {
        return {1045-10.2*score,229,25};
    }
    else if(score>=60)
    {
        return {229,10.2*score-587,25};
    }
    else
    {
        return {229,25,25};
    }
}

#endif // UTIL_H
