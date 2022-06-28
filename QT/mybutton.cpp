#include "mybutton.h"
#include <QDrag>
#include <QMimeData>
#include <QDropEvent>

DragButton::DragButton(QWidget* parent):QPushButton(parent)
{
    setAcceptDrops(true);
}

DragButton::DragButton(const QString& text, QWidget* parent)
    :QPushButton(text,parent)
{
    setAcceptDrops(true);
}

DropButton::DropButton(QWidget* parent):QPushButton(parent)
{
    setAcceptDrops(true);
}

DropButton::DropButton(const QString& text, QWidget* parent)
    :QPushButton(text,parent)
{
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
        setText(event->mimeData()->text());
        setStyleSheet("background-color: rgb(220,220,220)");
    }
}

void DropButton::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}
