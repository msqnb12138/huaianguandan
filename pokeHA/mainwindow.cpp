#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startgame.cpp"
#include "player.h"
#include "play.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("MainWindow{border-image:url(:/其他图片/SOURSES/01.jpg);}");
    startgame(this,button,location,turn);                        //发牌

}



MainWindow::~MainWindow()
{

    delete ui;
}
