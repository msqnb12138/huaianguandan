#include "mainwindow.h"
#include "card.h"
#include "player.h"
#include "play.h"
#include <QApplication>
#include <ctime>
#include <QPushButton>
#include <windows.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMaximumSize(1180,640);
    w.setMinimumSize(1180,640);
    w.show();
    a.exec();
    return 0;

}



