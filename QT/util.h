#ifndef UTIL_H
#define UTIL_H

#include <deque>
#include <math.h>
#include <stack>

struct Coordinate
{
    double x;
    double y;
    Coordinate(double xValue=0, double yValue=0)
    {
        x=xValue;
        y=yValue;
    }
    bool operator==(const Coordinate& right) const
    {
        return abs(x-right.x)<0.000001&&abs(y-right.y)<0.000001;
    }
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

inline void getWay(char** map, bool** visited, int mapHeight, int mapWidth, int startX, int startY, std::stack<Coordinate>& ways, bool& hasFound)
{
    if (map[startX][startY] == 'E')
    {
        hasFound = true;
        return;
    }
    if (startX > 0&&map[startX-1][startY]!='A'&&visited[startX-1][startY]==false)
    {
        visited[startX-1][startY]=true;
        ways.push({startX-1,startY});
        getWay(map,visited,mapHeight,mapWidth,startX-1,startY,ways,hasFound);
        if(hasFound) return;
        ways.pop();
    }
    if (startX < mapHeight -1&&map[startX+1][startY]!='A'&&visited[startX+1][startY]==false)
    {
        visited[startX+1][startY]=true;
        ways.push({startX+1,startY});
        getWay(map,visited,mapHeight,mapWidth,startX+1,startY,ways,hasFound);
        if(hasFound) return;
        ways.pop();
    }
    if (startY > 0&&map[startX][startY-1]!='A'&&visited[startX][startY-1]==false)
    {
        visited[startX][startY-1]=true;
        ways.push({startX,startY-1});
        getWay(map,visited,mapHeight,mapWidth,startX,startY-1,ways,hasFound);
        if(hasFound) return;
        ways.pop();
    }
    if (startY < mapWidth-1&&map[startX][startY+1]!='A'&&visited[startX][startY+1]==false)
    {
        visited[startX][startY+1]=true;
        ways.push({startX,startY+1});
        getWay(map,visited,mapHeight,mapWidth,startX,startY+1,ways,hasFound);
        if(hasFound) return;
        ways.pop();
    }
}
#endif // UTIL_H
