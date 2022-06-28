#include "mybutton.h"
#include "gamelevel.h"
#include <QDrag>
#include <QMimeData>
#include <QDropEvent>

DragButton::DragButton(QWidget* parent):QPushButton(parent)
{
    this->parent=dynamic_cast<GameLevel*>(parent);
    setAcceptDrops(true);
}

DragButton::DragButton(const QString& text, QWidget* parent)
    :QPushButton(text,parent)
{
    this->parent=dynamic_cast<GameLevel*>(parent);
    setAcceptDrops(true);
}

DropButton::DropButton(QWidget* parent):QPushButton(parent)
{
    this->parent=dynamic_cast<GameLevel*>(parent);
    setAcceptDrops(true);
}

DropButton::DropButton(const QString& text, QWidget* parent)
    :QPushButton(text,parent)
{
    this->parent=dynamic_cast<GameLevel*>(parent);
    setAcceptDrops(true);
}

void DragButton::mouseMoveEvent(QMouseEvent* event)
{
    QDrag* drag=new QDrag(this);
    QMimeData* data=new QMimeData;
    data->setText(text());
    drag->setMimeData(data);
    drag->exec(Qt::MoveAction);
}

void DropButton::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasText())
    {
        auto s= event->mimeData()->text();
        if ((s=="TLE"||s=="WA"||s=="CE")&&parent->GPATimesTen>=10)
        {
            setText(s);
            setStyleSheet("background-color: rgb(220,220,220)");
            parent->GPATimesTen -= 10;
        }
        else if((s=="PE")&&parent->GPATimesTen>=5)
        {
            setText(s);
            setStyleSheet("background-color: rgb(220,220,220)");
            parent->GPATimesTen-=5;
        }
        else if((s=="RTE")&&parent->GPATimesTen>=20)
        {
            setText(s);
            setStyleSheet("background-color: rgb(220,220,220)");
            parent->GPATimesTen-=20;
        }
        parent->GPAComment->setText(tr(std::string("剩余 GPA: "+std::to_string(parent->GPATimesTen/10)+'.'+std::to_string(parent->GPATimesTen%10)).c_str()));
    }
}

void DropButton::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}
