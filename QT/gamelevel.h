#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QProgressBar>
#include "util.h"

class GameLevel: public QDialog
{
    Q_OBJECT

public:
    GameLevel(int height,int width, char** map, int enemyNum, QWidget* parent=nullptr);
    virtual ~GameLevel();

private slots:

signals:

private:
    int mapHeight;
    int mapWidth;
    int numOfEnemies;
    int numOfEnemiesKilled;
    double GPA;
    const int kindOfAttack=5;
    char** gameMap;
    QPushButton*** buttons;
    QPushButton** attack;
    QProgressBar* bar;
    QGridLayout* gridLayout;
    QVBoxLayout* layout;
    QLabel* comment;
    QLabel** attackCost;
};


#endif // GAME_LEVEL_H
