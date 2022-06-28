#include "gamelevel.h"
#include <QFont>
#include <QPalette>
#include "mybutton.h"
#include <string>

GameLevel::GameLevel(int height, int width, char **map, int enemyNum, QWidget *parent)
    :QDialog(parent)
{
    this->numOfEnemies=enemyNum;
    this->mapHeight=height;
    this->mapWidth=width;
    this->gameMap=map;
    this->numOfEnemiesKilled=0;
    this->GPATimesTen=40;

    setFixedSize(900,700);

    // 初始化按钮
    buttons=new QPushButton**[mapHeight];
    for(int i=0;i<mapHeight;++i)
    {
        buttons[i]=new QPushButton*[mapHeight];
        for(int j=0;j<mapWidth;++j)
        {
            if(gameMap[i][j]=='A') // 障碍物, 显示为不可用图标
            {
                buttons[i][j]=new QPushButton(this);
                buttons[i][j]->setEnabled(false);
                buttons[i][j]->setStyleSheet("background-color: rgb(205,205,205)");
            }
            else if(gameMap[i][j]=='R') // 可通行位置
            {
                buttons[i][j]=new QPushButton(this);
                QPalette q;
                q.setColor(QPalette::ButtonText,QColor(0,0,205));
                buttons[i][j]->setPalette(q);
                buttons[i][j]->setStyleSheet("background-color: rgb(0,0,205)");
                buttons[i][j]->setText("R");
            }
            else if(gameMap[i][j]=='T') // 可通行且可放置攻击塔
            {
                buttons[i][j]=new DropButton(this);
                QPalette q;
                q.setColor(QPalette::ButtonText,QColor(128,0,0));
                buttons[i][j]->setPalette(q);
                buttons[i][j]->setStyleSheet("background-color: rgb(128,0,0)");
                buttons[i][j]->setText("T");
            }
            else if(gameMap[i][j]=='E') // 终点
            {
                buttons[i][j]=new QPushButton(this);
                buttons[i][j]->setStyleSheet("background-color: rgb(25,229,25)");
                buttons[i][j]->setText("4.0");
                buttons[i][j]->setFont(QFont("Microsoft YaHei", 10, 25));
            }
        }
    }

    // 初始化进度条
    bar=new QProgressBar(this);
    bar->setValue(0);
    bar->resize(200,30);
    bar->move(600,50);
    bar->setTextVisible(false);

    // 初始化标签
    GPAComment=new QLabel(this);
    GPAComment->setText(tr(std::string("剩余 GPA: "+std::to_string(GPATimesTen/10)+'.'+std::to_string(GPATimesTen%10)).c_str()));
    GPAComment->setFont(QFont("Microsoft YaHei",15,36));
    GPAComment->move(50,30);
    GPAComment->resize(200,50);
    comment=new QLabel(this);
    comment->setText("费用: ");
    comment->setFont(QFont("Microsoft YaHei",10,25));
    attackCost=new QLabel*[kindOfAttack];
    for(int i=0;i<kindOfAttack;++i)
    {
        attackCost[i]=new QLabel(this);
        attackCost[i]->setFont(QFont("Microsoft YaHei",10,25));
    }
    attackCost[0]->setText("  1");
    attackCost[1]->setText("  1");
    attackCost[2]->setText("  1");
    attackCost[3]->setText(" 0.5");
    attackCost[4]->setText("  2");


    // 初始化攻击塔列表
    attack=new QPushButton*[kindOfAttack];
    for(int i=0;i<kindOfAttack;++i)
    {
        attack[i]=new DragButton(this);
        attack[i]->setFont(QFont("Microsoft YaHei", 8,25));
        attack[i]->setStyleSheet("background-color: rgb(220,220,220)");
    }
    QPalette q, p;
    q.setColor(QPalette::ButtonText, QColor(220,20,60));
    attack[0]->setPalette(q);
    attack[1]->setPalette(q);
    attack[3]->setPalette(q);
    attack[4]->setPalette(q);
    p.setColor(QPalette::ButtonText, QColor(0,128,0));
    attack[2]->setPalette(p);

    attack[0]->setText("WA");
    attack[1]->setText("TLE");
    attack[2]->setText("CE");
    attack[3]->setText("PE");
    attack[4]->setText("RTE");

    // 初始化布局

    gridLayout=new QGridLayout(this);
    layout=new QVBoxLayout(this);
    for(int i=0;i<mapHeight;++i)
    {
        for(int j=0;j<mapWidth;++j)
        {
            gridLayout->addWidget(buttons[i][j],i,j);
        }
    }
    for(int i=0;i<5;++i)
    {
        gridLayout->addWidget(attack[i],1+mapHeight,(mapWidth-5)/2+i,2,1);
        gridLayout->addWidget(attackCost[i],2+mapHeight,(mapWidth-5)/2+i,1,1);
    }
    gridLayout->addWidget(comment,2+mapHeight,(mapWidth-5)/2-3,1,2);
    gridLayout->setContentsMargins(150,100,150,100);
    layout->addLayout(gridLayout);


    setLayout(layout);
}


GameLevel::~GameLevel()
{
    for(int i=0;i<mapHeight;++i)
    {
        for(int j=0;j<mapWidth;++j)
        {
            delete buttons[i][j];
        }
        delete[] buttons[i];
    }
    delete[] buttons;
    for(int i=0;i<kindOfAttack;++i)
    {
        delete attack[i];
    }
    delete[] attack;
    for(int i=0;i<kindOfAttack;++i)
    {
        delete attackCost[i];
    }
    delete[] attackCost;
}
