#include "mainwindow.h"
#include <QApplication>

// Hello World! by zml72062

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
