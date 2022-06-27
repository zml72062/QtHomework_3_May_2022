#include "mainwindow.h"
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      widget(new QWidget),
      gameTitle(new QLabel(this)),
      mainButton(new QPushButton(this)),
      exitButton(new QPushButton(this))
{
    setCentralWidget(widget);
    QGridLayout* gridLayout=new QGridLayout(this);
    QHBoxLayout* layout=new QHBoxLayout(this);
    // 主界面样式设定
    setWindowTitle("保卫 4.0");
    setMaximumSize(2000,1000);
    setMinimumSize(1200,600);
    setWindowIcon(QIcon(":/ico/mainIcon"));

    // 文字设定
    gameTitle->setText("保卫 4.0");
    gameTitle->setFont(QFont("Microsoft YaHei", 30,36));
    gameTitle->resize(300,60);


    // 按钮设定
    mainButton->setText("开始游戏");
    mainButton->setFont(QFont("Microsoft YaHei", 20, 36));
    mainButton->resize(200,80);

    exitButton->setText("退出");
    exitButton->setFont(QFont("Microsoft YaHei", 20, 36));
    exitButton->resize(200,80);

    connect(mainButton, &QPushButton::clicked, this, &MainWindow::selectLevels);
    connect(exitButton, &QPushButton::clicked,this,&QMainWindow::close);

    gridLayout->addWidget(gameTitle,0,2,3,1,Qt::AlignCenter);
    gridLayout->addWidget(mainButton,3,0,2,1);
    gridLayout->addWidget(exitButton,3,3,2,1);
    layout->addLayout(gridLayout);
    layout->setContentsMargins(100,100,100,100);
    widget->setLayout(layout);
}

void MainWindow::selectLevels()
{

}

MainWindow::~MainWindow()
{
    delete widget;
}
