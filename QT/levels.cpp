#include "levels.h"
#include <QFont>
#include <QICon>
#include "gamelevel.h"

Levels::Levels(QWidget *parent):
    QDialog(parent),
    title(new QLabel(this))
{
    // 窗口设定
    setModal(true);
    setWindowTitle("保卫 4.0");
    setWindowIcon(QIcon(":/ico/mainIcon"));
    setFixedSize(800,400);

    // 标题设定
    title->setText("选择关卡");
    title->setFont(QFont("Microsoft YaHei", 25, 36));
    // 按钮设定
    for(auto&p:levelButton)
    {
        p=new QPushButton(this);
    }
    levelButton[0]->setText("大一上学期");
    levelButton[1]->setText("大一下学期");
    levelButton[2]->setText("大二上学期");
    levelButton[3]->setText("大二下学期");
    levelButton[4]->setText("大三上学期");
    levelButton[5]->setText("大三下学期");
    levelButton[6]->setText("大四上学期");
    levelButton[7]->setText("大四下学期");
    levelButton[0]->setFont(QFont("Microsoft YaHei", 15, 25));
    levelButton[1]->setFont(QFont("Microsoft YaHei", 15, 25));
    levelButton[2]->setFont(QFont("Microsoft YaHei", 15, 25));
    levelButton[3]->setFont(QFont("Microsoft YaHei", 15, 25));
    levelButton[4]->setFont(QFont("Microsoft YaHei", 15, 25));
    levelButton[5]->setFont(QFont("Microsoft YaHei", 15, 25));
    levelButton[6]->setFont(QFont("Microsoft YaHei", 15, 25));
    levelButton[7]->setFont(QFont("Microsoft YaHei", 15, 25));
    levelButton[0]->setEnabled(true);
    levelButton[1]->setEnabled(false);
    levelButton[2]->setEnabled(false);
    levelButton[3]->setEnabled(false);
    levelButton[4]->setEnabled(false);
    levelButton[5]->setEnabled(false);
    levelButton[6]->setEnabled(false);
    levelButton[7]->setEnabled(false);


    quitButton=new QPushButton(this);
    quitButton->setText("退出");
    quitButton->setFont(QFont("Microsoft YaHei", 15, 25));
    quitButton->resize(200,120);
    connect(quitButton,&quitButton->clicked,this,&Levels::close);
    connect(levelButton[0],&QPushButton::clicked,this,&Levels::gotoLevel1);
    connect(levelButton[1],&QPushButton::clicked,this,&Levels::gotoLevel2);
    connect(levelButton[2],&QPushButton::clicked,this,&Levels::gotoLevel3);
    connect(levelButton[3],&QPushButton::clicked,this,&Levels::gotoLevel4);
    connect(levelButton[4],&QPushButton::clicked,this,&Levels::gotoLevel5);
    connect(levelButton[5],&QPushButton::clicked,this,&Levels::gotoLevel6);
    connect(levelButton[6],&QPushButton::clicked,this,&Levels::gotoLevel7);
    connect(levelButton[7],&QPushButton::clicked,this,&Levels::gotoLevel8);


    // 进度条设定
    bar=new QProgressBar(this);
    bar->setValue(0);
    bar->resize(200,30);
    bar->move(500,50);

    // 布局设定
    blocksLayout=new QGridLayout(this);
    blocksLayout->addWidget(title,0,0,4,1,Qt::AlignTop|Qt::AlignHCenter);
    blocksLayout->addWidget(levelButton[0],1,0,1,1);
    blocksLayout->addWidget(levelButton[1],1,1,1,1);
    blocksLayout->addWidget(levelButton[2],1,2,1,1);
    blocksLayout->addWidget(levelButton[3],1,3,1,1);
    blocksLayout->addWidget(levelButton[4],2,0,1,1);
    blocksLayout->addWidget(levelButton[5],2,1,1,1);
    blocksLayout->addWidget(levelButton[6],2,2,1,1);
    blocksLayout->addWidget(levelButton[7],2,3,1,1);
    blocksLayout->addWidget(quitButton,3,3,2,1,Qt::AlignRight);
    layout=new QVBoxLayout(this);
    layout->addLayout(blocksLayout);
    layout->setSpacing(10);
    setLayout(layout);

}

void Levels::gotoLevel1()
{
    char map[8][13]={"AAAAAAAAAAAA",
                     "RRRRRRAAAARR",
                     "AAAAARAAAATA",
                     "AAAAARAAAARA",
                     "AAAAARAAAARA",
                     "AAAAARAAAARA",
                     "AAAAARTRTRRA",
                     "AAAAAAAAAAAA"}
                     ;
    for(int i=0;i<8;++i)
    {
        if(i==1)
        {
            map[i][12]='E';
        }
        else
        {
            map[i][12]='A';
        }
    }
    char** myMap=new char*[8];
    for(int i=0;i<8;++i)
    {
        myMap[i]=new char[13];
        for(int j=0;j<13;++j)
        {
            myMap[i][j]=map[i][j];
        }
    }
    GameLevel* level1=new GameLevel(8,13,myMap,5,this);
    level1->setWindowTitle("大一上学期");
    level1->show();
    for(int i=0;i<8;++i)
    {
        delete[] myMap[i];
    }
    delete[] myMap;
    return;
}

void Levels::gotoLevel2()
{

}

void Levels::gotoLevel3()
{

}

void Levels::gotoLevel4()
{

}

void Levels::gotoLevel5()
{

}

void Levels::gotoLevel6()
{

}

void Levels::gotoLevel7()
{

}

void Levels::gotoLevel8()
{

}

void Levels::finishAnotherLevel()
{
    ++levelsFinished;
    if(levelsFinished>8)
    {
        levelsFinished=8;
    }
    switch(levelsFinished)
    {
    case 1:
        levelButton[0]->setEnabled(true);
        levelButton[1]->setEnabled(true);
        levelButton[2]->setEnabled(false);
        levelButton[3]->setEnabled(false);
        levelButton[4]->setEnabled(false);
        levelButton[5]->setEnabled(false);
        levelButton[6]->setEnabled(false);
        levelButton[7]->setEnabled(false);
        bar->setValue(12);
        break;
    case 2:
        levelButton[0]->setEnabled(true);
        levelButton[1]->setEnabled(true);
        levelButton[2]->setEnabled(true);
        levelButton[3]->setEnabled(false);
        levelButton[4]->setEnabled(false);
        levelButton[5]->setEnabled(false);
        levelButton[6]->setEnabled(false);
        levelButton[7]->setEnabled(false);
        bar->setValue(25);
        break;
    case 3:
        levelButton[0]->setEnabled(true);
        levelButton[1]->setEnabled(true);
        levelButton[2]->setEnabled(true);
        levelButton[3]->setEnabled(true);
        levelButton[4]->setEnabled(false);
        levelButton[5]->setEnabled(false);
        levelButton[6]->setEnabled(false);
        levelButton[7]->setEnabled(false);
        bar->setValue(37);
        break;
    case 4:
        levelButton[0]->setEnabled(true);
        levelButton[1]->setEnabled(true);
        levelButton[2]->setEnabled(true);
        levelButton[3]->setEnabled(true);
        levelButton[4]->setEnabled(true);
        levelButton[5]->setEnabled(false);
        levelButton[6]->setEnabled(false);
        levelButton[7]->setEnabled(false);
        bar->setValue(50);
        break;
    case 5:
        levelButton[0]->setEnabled(true);
        levelButton[1]->setEnabled(true);
        levelButton[2]->setEnabled(true);
        levelButton[3]->setEnabled(true);
        levelButton[4]->setEnabled(true);
        levelButton[5]->setEnabled(true);
        levelButton[6]->setEnabled(false);
        levelButton[7]->setEnabled(false);
        bar->setValue(63);
        break;
    case 6:
        levelButton[0]->setEnabled(true);
        levelButton[1]->setEnabled(true);
        levelButton[2]->setEnabled(true);
        levelButton[3]->setEnabled(true);
        levelButton[4]->setEnabled(true);
        levelButton[5]->setEnabled(true);
        levelButton[6]->setEnabled(true);
        levelButton[7]->setEnabled(false);
        bar->setValue(75);
        break;
    case 7:
        levelButton[0]->setEnabled(true);
        levelButton[1]->setEnabled(true);
        levelButton[2]->setEnabled(true);
        levelButton[3]->setEnabled(true);
        levelButton[4]->setEnabled(true);
        levelButton[5]->setEnabled(true);
        levelButton[6]->setEnabled(true);
        levelButton[7]->setEnabled(true);
        bar->setValue(88);
        break;
    case 8:
        levelButton[0]->setEnabled(true);
        levelButton[1]->setEnabled(true);
        levelButton[2]->setEnabled(true);
        levelButton[3]->setEnabled(true);
        levelButton[4]->setEnabled(true);
        levelButton[5]->setEnabled(true);
        levelButton[6]->setEnabled(true);
        levelButton[7]->setEnabled(true);
        bar->setValue(100);
        break;
    }
}

Levels::~Levels()
{

}
