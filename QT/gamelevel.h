#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include <QDialog>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QProgressBar>
#include <QTimer>
#include "util.h"

class DropButton;
class DragButton;
class EnemyBase;

class GameLevel: public QDialog
{
    Q_OBJECT

public:
    GameLevel(int height,int width, char** map, int enemyNum, QWidget* parent=nullptr);
    virtual ~GameLevel();
    friend class DropButton;
    friend class DragButton;

    char** gameMap;
    // 返回左上角顶点坐标
    int startX() const
    {
        return buttons[0][0]->x();
    }
    int startY() const
    {
        return buttons[0][0]->y();
    }
    // 返回相邻格点之间的 (有效) 间距
    int effHeight() const
    {
        return buttons[1][0]->y()-buttons[0][0]->y();
    }
    int effWidth() const
    {
        return buttons[0][1]->x()-buttons[0][0]->x();
    }

    void updateScene();
    void updateGenerate();
    void draw();
    void produceEnemy();
    void paintEvent(QPaintEvent*);

private slots:

signals:

private:
    void generateStarts()
    {
        for(int i=0;i<mapHeight;++i)
        {
            if(gameMap[i][0]=='R')
            {
                startPoints.push_back({i,0});
            }
            if(gameMap[i][mapWidth-1]=='R')
            {
                startPoints.push_back({i,mapWidth-1});
            }
        }
        for(int i=0;i<mapWidth;++i)
        {
            if(gameMap[0][i]=='R')
            {
                startPoints.push_back({0,i});
            }
            if(gameMap[mapHeight-1][i]=='R')
            {
                startPoints.push_back({mapHeight-1,i});
            }
        }
    }

    void generatePaths()
    {
        int n=startPoints.size();
        for(int k=0;k<n;++k)
        {
            bool** visited=new bool*[mapHeight];
            for(int i=0;i<mapHeight;++i)
            {
                visited[i]=new bool[mapWidth];
                for(int j=0;j<mapWidth;++j)
                {
                    visited[i][j]=false;
                }
            }
            std::stack<Coordinate> st;
            st.push({startPoints[k].x,startPoints[k].y});
            bool hasFound=false;
            getWay(gameMap,visited,mapHeight,mapWidth,startPoints[k].x,startPoints[k].y,st,hasFound);
            movePaths.push_back(std::deque<Coordinate>(st.size()));
            int q=st.size();
            for(int l=q;l>0;--l)
            {
                movePaths.back()[l-1]=st.top();
                st.pop();
            }
            for(int i=0;i<mapHeight;++i)
            {
                delete[] visited[i];
            }
            delete[] visited;
        }
    }

    int mapHeight;
    int mapWidth;
    int numOfEnemies;
    int numOfEnemiesKilled;
    int GPATimesTen;
    const int kindOfAttack=5;

    std::deque<Coordinate> startPoints;
    std::deque<std::deque<Coordinate>> movePaths;
    QPushButton*** buttons;
    QPushButton** attack;
    QProgressBar* bar;
    QGridLayout* gridLayout;
    QVBoxLayout* layout;
    std::deque<EnemyBase*> enemyList;
    std::deque<EnemyBase*> enemyWaitedList;
    QTimer* timerForMoving;
    QTimer* timerForGenerating;
    QLabel* comment;
    QLabel* GPAComment;
    QLabel** attackCost;
};


#endif // GAME_LEVEL_H
