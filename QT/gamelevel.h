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
    GameLevel(int mapWidth, int mapHeight, int numOfEnemies, QWidget *parent=nullptr);
    virtual ~GameLevel();

private slots:

signals:

private:
    int mapHeight;
    int mapWidth;
    char** gameMap;
    QPushButton*** buttons;
    QProgressBar* bar;
    std::deque<Enemy>* enemyList;
};


#endif // GAME_LEVEL_H
