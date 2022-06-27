#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

private slots:
    void selectLevels();

private:
    QWidget* widget;
    QLabel* gameTitle;
    QPushButton* mainButton;
    QPushButton* exitButton;
};

#endif // MAINWINDOW_H
