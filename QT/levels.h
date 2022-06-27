#ifndef LEVELS_H
#define LEVELS_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class Levels: public QWidget
{
    Q_OBJECT

public:
    Levels(QWidget* parent=nullptr);
    virtual ~Levels();

private slots:
//    void gotoLevel1();
//    void gotoLevel2();
//    void gotoLevel3();
//    void gotoLevel4();
//    void gotoLevel5();
//    void gotoLevel6();
//    void gotoLevel7();
//    void gotoLevel8();

private:
    QLabel* title;
    QPushButton* levelButton[8];

};


#endif // LEVELS_H
