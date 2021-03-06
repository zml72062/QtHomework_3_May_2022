#include "gamelevel.h"
#include <QFont>
#include <QPalette>
#include "mybutton.h"
#include <string>
#include "enemy.h"
#include "enemy1.h"
#include "enemy2.h"
#include "enemy3.h"
#include "enemy4.h"
#include <QPainter>
#include <random>
#include <ctime>
#include "windialog.h"
#include "levels.h"

GameLevel::GameLevel(int height, int width, char **map, int enemyNum,int waitTime, int initCoin, QWidget *parent)
    : QDialog(parent)
{
    this->numOfEnemies = enemyNum;
    this->mapHeight = height;
    this->mapWidth = width;
    this->gameMap = map;
    this->numOfEnemiesKilled = 0;
    this->GPATimesTen = 10*initCoin;
    enemyWaitedList = std::deque<EnemyBase *>(enemyNum, nullptr);
    generateStarts();
    generatePaths();
    setFixedSize(900, 700);

    // 生成随机等待列表
    std::default_random_engine rng(std::time(nullptr));
    std::uniform_real_distribution<> u(0, 1);
    for (auto &p : enemyWaitedList)
    {
        // 4 应改为怪的种类数
        int next = static_cast<int>(4 * u(rng));
        int nextEntry = static_cast<int>(startPoints.size() * u(rng));
        if (next == 0)
        {
            p = new Enemy1(movePaths[nextEntry], this);
        }
        else if (next == 1)
        {
            p = new Enemy2(movePaths[nextEntry], this);
        }
        else if (next == 2)
        {
            p = new Enemy3(movePaths[nextEntry], this);
        }
        else if (next == 3)
        {
            p = new Enemy4(movePaths[nextEntry], this);
        }
    }

    // 初始化按钮
    buttons = new QPushButton **[mapHeight];
    for (int i = 0; i < mapHeight; ++i)
    {
        buttons[i] = new QPushButton *[mapHeight];
        for (int j = 0; j < mapWidth; ++j)
        {
            if (gameMap[i][j] == 'A') // 障碍物, 显示为不可用图标
            {
                buttons[i][j] = new QPushButton(this);
                buttons[i][j]->setEnabled(false);
                buttons[i][j]->setStyleSheet("background-color: rgb(205,205,205)");
            }
            else if (gameMap[i][j] == 'R') // 可通行位置
            {
                buttons[i][j] = new QPushButton(this);
                QPalette q;
                q.setColor(QPalette::ButtonText, QColor(0, 0, 205));
                buttons[i][j]->setPalette(q);
                buttons[i][j]->setStyleSheet("background-color: rgb(0,0,205)");
                buttons[i][j]->setFlat(true);
            }
            else if (gameMap[i][j] == 'T') // 可通行且可放置攻击塔
            {
                buttons[i][j] = new DropButton(this);
                QPalette q;
                q.setColor(QPalette::ButtonText, QColor(128, 0, 0));
                buttons[i][j]->setPalette(q);
                buttons[i][j]->setStyleSheet("background-color: rgb(128,0,0)");
                buttons[i][j]->setText("T");
            }
            else if (gameMap[i][j] == 'E') // 终点
            {
                buttons[i][j] = new QPushButton(this);
                buttons[i][j]->setStyleSheet("background-color: rgb(25,229,25)");
                buttons[i][j]->setText("4.0");
                buttons[i][j]->setFont(QFont("Microsoft YaHei", 10, 25));
            }
        }
    }

    // 初始化进度条
    bar = new QProgressBar(this);
    bar->setValue(0);
    bar->resize(200, 30);
    bar->move(600, 50);
    bar->setTextVisible(false);
    this->parent=dynamic_cast<QDialog*>(parent);
    // 初始化标签
    GPAComment = new QLabel(this);
    GPAComment->setText(tr(std::string("剩余 GPA: " + std::to_string(GPATimesTen / 10) + '.' + std::to_string(GPATimesTen % 10)).c_str()));
    GPAComment->setFont(QFont("Microsoft YaHei", 15, 36));
    GPAComment->move(50, 30);
    GPAComment->resize(200, 50);
    comment = new QLabel(this);
    comment->setText("费用: ");
    comment->setFont(QFont("Microsoft YaHei", 10, 25));
    attackCost = new QLabel *[kindOfAttack];
    for (int i = 0; i < kindOfAttack; ++i)
    {
        attackCost[i] = new QLabel(this);
        attackCost[i]->setFont(QFont("Microsoft YaHei", 10, 25));
    }
    attackCost[0]->setText("  1");
    attackCost[1]->setText("  1");
    attackCost[2]->setText("  1");
    attackCost[3]->setText(" 0.5");
    attackCost[4]->setText("  2");

    // 初始化攻击塔列表
    attack = new QPushButton *[kindOfAttack];
    for (int i = 0; i < kindOfAttack; ++i)
    {
        attack[i] = new DragButton(this);
        attack[i]->setFont(QFont("Microsoft YaHei", 8, 25));
        attack[i]->setStyleSheet("background-color: rgb(220,220,220)");
    }
    QPalette q, p;
    q.setColor(QPalette::ButtonText, QColor(220, 20, 60));
    attack[0]->setPalette(q);
    attack[1]->setPalette(q);
    attack[3]->setPalette(q);
    attack[4]->setPalette(q);
    p.setColor(QPalette::ButtonText, QColor(0, 128, 0));
    attack[2]->setPalette(p);

    attack[0]->setText("WA");
    attack[1]->setText("TLE");
    attack[2]->setText("CE");
    attack[3]->setText("PE");
    attack[4]->setText("RTE");

    // 初始化布局

    gridLayout = new QGridLayout(this);
    layout = new QVBoxLayout(this);
    for (int i = 0; i < mapHeight; ++i)
    {
        for (int j = 0; j < mapWidth; ++j)
        {
            gridLayout->addWidget(buttons[i][j], i, j);
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        gridLayout->addWidget(attack[i], 1 + mapHeight, (mapWidth - 5) / 2 + i, 2, 1);
        gridLayout->addWidget(attackCost[i], 2 + mapHeight, (mapWidth - 5) / 2 + i, 1, 1);
    }
    gridLayout->addWidget(comment, 2 + mapHeight, (mapWidth - 5) / 2 - 3, 1, 2);
    gridLayout->setContentsMargins(150, 100, 150, 100);
    layout->addLayout(gridLayout);

    // 设置计时器
    timerForMoving = new QTimer(this);
    timerForMoving->start(30);
    timerForGenerating = new QTimer(this);
    timerForGenerating->start(waitTime);
    enemyInvaded=0;

    connect(timerForMoving, &QTimer::timeout, this, &GameLevel::updateScene);
    connect(timerForGenerating, &QTimer::timeout, this, &GameLevel::updateGenerate);
    connect(this, &GameLevel::win, this, &GameLevel::commentWin);
    connect(this, &GameLevel::win, dynamic_cast<Levels*>(this->parent), &Levels::finishAnotherLevel);
    //    connect(enemyList[0],&EnemyBase::reached, this, &GameLevel::close);

    setLayout(layout);
}

GameLevel::~GameLevel()
{
    for (int i = 0; i < mapHeight; ++i)
    {
        for (int j = 0; j < mapWidth; ++j)
        {
            delete buttons[i][j];
        }
        delete[] buttons[i];
    }
    delete[] buttons;
    for (int i = 0; i < kindOfAttack; ++i)
    {
        delete attack[i];
    }
    delete[] attack;
    for (int i = 0; i < kindOfAttack; ++i)
    {
        delete attackCost[i];
    }
    delete[] attackCost;
}

void GameLevel::paintEvent(QPaintEvent *e)
{
    draw();
}

void GameLevel::updateScene()
{
    for (auto &i : enemyList)
    {
        i->move();
    }
    update();
}

void GameLevel::updateGenerate()
{
    if (!enemyWaitedList.empty())
    {
        enemyList.push_back(enemyWaitedList[0]);
        enemyWaitedList.pop_front();
    }
    update();
}

void GameLevel::draw()
{
    QPainter painter(this);
    for (auto &i : enemyList)
    {
        QPixmap pix;
        pix.load(i->imagePath);
        int xPix = i->xPixel(i->position);
        int yPix = i->yPixel(i->position);
        painter.drawPixmap(xPix, yPix, i->parent->effWidth() / 2, i->parent->effHeight() / 2, pix);
    }
}

void GameLevel::clear(int type, int x, int y)
{
    qDebug()<<"clear";
    for (auto p = enemyList.begin(); p != enemyList.end(); ++p)
    {
        if ((int)((*p)->position.x+0.001) == x && (int)((*p)->position.y+0.001) == y && (*p)->type == type&&((*p)->currentHealth<=0.001||(*p)->speed<=0.001))
        {
             enemyList.erase(p);
             qDebug()<<"die";
            break;
        }
    }
    ++numOfEnemiesKilled;
    GPATimesTen += ((type == 3) ? 20 : 10);
    GPAComment->setText(tr(std::string("剩余 GPA: " + std::to_string(GPATimesTen / 10) + '.' + std::to_string(GPATimesTen % 10)).c_str()));
    bar->setValue(numOfEnemiesKilled * 100 / numOfEnemies);
    if (numOfEnemiesKilled == numOfEnemies)
    {
        emit win();
    }
}

void GameLevel::clearIcon(int x, int y)
{
    if (buttons[x][y]->text() == "T")
    {
        return;
    }
    else
    {
        QPalette q;
        q.setColor(QPalette::ButtonText, QColor(128, 0, 0));
        buttons[x][y]->setPalette(q);
        buttons[x][y]->setStyleSheet("background-color: rgb(128,0,0)");
        buttons[x][y]->setText("T");
    }
}

void GameLevel::commentWin()
{
    winDialog* win=new winDialog(this);
    win->setModal(true);
    win->show();
}

