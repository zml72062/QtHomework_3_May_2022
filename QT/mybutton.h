#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>

class DropButton: public QPushButton
{
    Q_OBJECT
public:
    DropButton(QWidget* parent=nullptr);
    DropButton(const QString& text, QWidget* parent=nullptr);
    virtual ~DropButton(){}
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dropEvent(QDropEvent* event);
};

class DragButton: public QPushButton
{
    Q_OBJECT
public:
    DragButton(QWidget* parent=nullptr);
    DragButton(const QString& text, QWidget* parent=nullptr);
    virtual ~DragButton(){}
    virtual void mouseMoveEvent(QMouseEvent* event);
};

#endif // MYBUTTON_H
