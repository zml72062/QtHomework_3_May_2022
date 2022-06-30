#ifndef WINDIALOG_H
#define WINDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>

class winDialog:public QDialog
{
    Q_OBJECT

public:
    winDialog(QWidget* parent=nullptr)
        :QDialog(parent)
    {
        setFixedSize(250,120);
        setWindowTitle("胜利");
        setWindowIcon(QIcon(":/ico/mainIcon"));

        button=new QPushButton(this);
        button->setText("退出");

        layout=new QVBoxLayout(this);
        layout->addWidget(button);
        setLayout(layout);

        connect(button, &QPushButton::clicked, this, &QDialog::close);
        connect(button, &QPushButton::clicked, dynamic_cast<QDialog*>(parent), &QDialog::close);
    }

    virtual ~winDialog(){}
private:
    QPushButton* button;
    QVBoxLayout* layout;
};

#endif // WINDIALOG_H
