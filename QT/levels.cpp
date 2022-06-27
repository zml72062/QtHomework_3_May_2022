#include "levels.h"
#include <QFont>

Levels::Levels(QWidget *parent):
    QWidget(parent),
    title(new QLabel(this))
{
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

}

Levels::~Levels()
{

}
