#ifndef LEVELS_H
#define LEVELS_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QProgressBar>

class Levels: public QDialog
{
    Q_OBJECT

public:
    Levels(QWidget* parent=nullptr);
    virtual ~Levels();

private slots:
    void gotoLevel1();
    void gotoLevel2();
    void gotoLevel3();
    void gotoLevel4();
    void gotoLevel5();
    void gotoLevel6();
    void gotoLevel7();
    void gotoLevel8();
    void finishAnotherLevel();

private:
    int levelsFinished=0;
    QLabel* title;
    QPushButton* levelButton[8];
    QVBoxLayout* layout;
    QGridLayout* blocksLayout;
    QPushButton* quitButton;
    QProgressBar* bar;
};


#endif // LEVELS_H
