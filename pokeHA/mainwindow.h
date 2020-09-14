#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QDebug>
#include "player.h"
#include "play.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int location[108];                          //创建位置数组并随即分配
    play now;
    play  past;
    card  *poke;
    QPushButton  button[108];                    //创建牌组按钮
    int turn=0;
    int pasttype=0;
    int round=10086;
    player  players[4];                          //创建四个玩家数据
    int  find[108];                              //记录每个位置上的牌号


    void setothers(QString q){
        ui->others->setText(q);
    }
    void setturn(QString q){
        ui->turn->setText(q);
    }
    void setpast(QString q){
        ui->past->insertPlainText(q);
        ui->past->insertPlainText(" ");
    }
    void clearothers(){
        ui->others->clear();
    }
    void clearturn(){
        ui->turn->clear();
    }
    void clearpast(){
        ui->past->clear();
    }

    void skip(){
            clearothers();

            if(round==10086){
                this->setothers("当前您不可以不出！");
                return;
            }

            turn++;
            turn=turn%4;
            while(players[turn].win==1){
                turn++;
                turn=turn%4;
            }


            if(turn==0)
                this->setturn("玩家1出牌");
            else if(turn==1)
                this->setturn("玩家2出牌");
            else if(turn==2)
                this->setturn("玩家3出牌");
            else
                this->setturn("玩家4出牌");

            round++;
            if(round==3){
                round=10086;
                for(int i=0;i<27;i++){
                    past.decor[i]=0;
                    past.number=0;
                    past.size[i]=0;
                    pasttype=0;
                }
                ui->tonghuashun->clear();
                this->clearpast();
            }
    }


    void chupai(){
        clearothers();
        now.number=0;
        for(int i=0;i<27;i++){
            now.size[i]=0;
            now.decor[i]=0;
        }


        if(turn==0){
            for(int i=0;i<27;i++){
                if(poke[find[i]].up==1){
                    now.decor[now.number]=poke[find[i]].decor;
                    now.size[now.number]=poke[find[i]].size;
                    now.szz[now.number]=poke[find[i]].szz;
                    now.number++;
                }
            }
        }
        else if(turn==1){
            for(int i=54;i<81;i++){
                if(poke[find[i]].up==1){
                    now.decor[now.number]=poke[find[i]].decor;
                    now.size[now.number]=poke[find[i]].size;
                    now.szz[now.number]=poke[find[i]].szz;
                    now.number++;
                }
            }
        }
        else if(turn==2){
            for(int i=27;i<54 ;i++){
                if(poke[find[i]].up==1){
                    now.decor[now.number]=poke[find[i]].decor;
                    now.size[now.number]=poke[find[i]].size;
                    now.szz[now.number]=poke[find[i]].szz;
                    now.number++;
                }
            }
        }
        else{
            for(int i=81;i<108;i++){
                if(poke[find[i]].up==1){
                    now.decor[now.number]=poke[find[i]].decor;
                    now.size[now.number]=poke[find[i]].size;
                    now.szz[now.number]=poke[find[i]].szz;
                    now.number++;
                }
            }
        }

        for(int i=0;i<27;i++){
            if(now.size[i+1]==0)
                break;
            else{
                for(int p=0;p<27;p++){
                    if(now.size[p+1]==0)
                        break;
                    else{
                        if(now.size[p]>now.size[p+1]){
                            int h;
                            h=now.size[p];
                            now.size[p]=now.size[p+1];
                            now.size[p+1]=h;
                        }
                        if(now.szz[p]>now.szz[p+1]){
                            int h;
                            h=now.szz[p];
                            now.szz[p]=now.szz[p+1];
                            now.szz[p+1]=h;
                        }
                    }
                }
            }
        }

        int nowtype=now.type();                                            //获取出牌类型

        if(nowtype==11){
            this->setothers("您选择了错误的牌型！");
            return;
        }

        if(pasttype!=0){
            if(nowtype==0)
                this->setothers("请选择要出的牌！");
            if(nowtype==10&&pasttype==10){
                if(now.number<past.number)
                    this->setothers("您的牌需要大于上家！");
                else if(now.number==past.number&&now.size[0]<=past.size[0])
                    this->setothers("您的牌需要大于上家！");
                else{
                    suc(nowtype);
                }
            }
            else if(nowtype==10&&pasttype!=10&&pasttype!=6){
                    suc(nowtype);
            }
            else if(nowtype==6&&pasttype!=10&&pasttype!=6){
                    suc(nowtype);
            }
            else if(nowtype==10&&pasttype==6){
                    if(now.number<6)
                        this->setothers("您的牌需要大于上家！");
                    else
                        suc(nowtype);
            }
            else if(nowtype==6&&pasttype==10){
                if(past.number>5)
                    this->setothers("您的牌需要大于上家！");
                else
                    suc(nowtype);
            }









            else if(nowtype!=pasttype&&nowtype!=6&&nowtype!=10){                                          //错误信息提示

                if(pasttype==6||pasttype==10)
                    this->setothers("您的牌需要大于上家！");

                else if(nowtype==0)
                    this->setothers("请选择要出的牌！");
                else
                    this->setothers("您选择了错误的牌型！");
            }
            else{
                if(now.size[0]<=past.size[0]){
                    this->setothers("您的牌需要大于上家！");
                }
                else{                                                       //出牌成功
                    suc(nowtype);
                }
            }
        }
        else{
            if(nowtype==11){
                this->setothers("您选择了错误的牌型！");
                return;
            }


            pasttype=nowtype;

            if(nowtype==0){
                this->setothers("请选择要出的牌！");
            }
            else if(nowtype==11){
                this->setothers("您选择了错误的牌型！");
            }
            else{                                                       //第一次出牌
                suc(nowtype);
            }
        }










        for(int i=0;i<108;i++){                                             //每次出牌后归位
            if(poke[i].up==1){
                poke[i].up=0;
                if(poke[i].loc<27)
                    button[poke[i].loc].move(button[poke[i].loc].x(),button[poke[i].loc].y()-20);
                else if(poke[i].loc<54)
                    button[poke[i].loc].move(button[poke[i].loc].x(),button[poke[i].loc].y()+20);
                else if(poke[i].loc<81)
                    button[poke[i].loc].move(button[poke[i].loc].x()-20,button[poke[i].loc].y());
                else
                    button[poke[i].loc].move(button[poke[i].loc].x()+20,button[poke[i].loc].y());
            }
        }



        for(int i=0;i<4;i++){
            if(players[i].last==0&&players[i].win==0){
                players[i].win=1;
                char p[20];
                sprintf(p,"玩家%d已胜出",i+1);
                this->setothers(p);
                break;
            }
        }
    }



    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void suc(int nowtype){
        round=0;                                                //出牌成功
        clearothers();

        for(int i=0;i<27;i++){
          past.size[i]=now.size[i];
          past.decor[i]=now.decor[i];
        }
        pasttype=nowtype;
        past.number=now.number;
        players[turn].last-=now.number;

        this->clearpast();
        ui->tonghuashun->clear();
        if(turn==0){                                            //输出上家排面
            for(int i=0;i<27;i++){
                if(poke[find[i]].up==1)
                    this->setpast(poke[find[i]].paimian);
            }
        }
        else if(turn==1){
            for(int i=54;i<81;i++){
                if(poke[find[i]].up==1)
                    this->setpast(poke[find[i]].paimian);
            }
        }
        else if(turn==2){
            for(int i=27;i<54;i++){
                if(poke[find[i]].up==1)
                    this->setpast(poke[find[i]].paimian);
            }
        }
        else if(turn==3){
            for(int i=81;i<108;i++){
                if(poke[find[i]].up==1)
                    this->setpast(poke[find[i]].paimian);
            }
        }

        if(nowtype==6)
            ui->tonghuashun->setText("同花顺");

        if(turn==0){                                            //将选中的牌打出
            for(int i=0;i<27;i++){
                if(poke[find[i]].up==1){
                   button[i].hide();
                   poke[find[i]].out=1;
                }
            }
            for(int i=26;i>=0;i--){
                if(poke[find[i]].out==1){
                    for(int p=i+1;p<27;p++){
                        button[p].move(button[p].x()-23,button[p].y());
                    }
                }
            }
        }
        else if(turn==1){
            for(int i=54;i<81;i++){
                if(poke[find[i]].up==1){
                   button[i].hide();
                   poke[find[i]].out=1;
                }
            }

            for(int i=80;i>=54;i--){
                if(poke[find[i]].out==1){
                    for(int p=i+1;p<81;p++){
                        button[p].move(button[p].x(),button[p].y()-19);
                    }
                }
            }

        }
        else if(turn==2){
            for(int i=27;i<54;i++){
                if(poke[find[i]].up==1){
                   button[i].hide();
                   poke[find[i]].out=1;
                }
            }
            for(int i=53;i>=27;i--){
                if(poke[find[i]].out==1){
                    for(int p=i;p<54;p++){
                        button[p].move(button[p].x()-23,button[p].y());
                    }
                }
            }

        }
        else{
            for(int i=81;i<108;i++){
                if(poke[find[i]].up==1){
                   button[i].hide();
                   poke[find[i]].out=1;
                }
            }
            for(int i=107;i>=81;i--){
                if(poke[find[i]].out==1){
                    for(int p=i;p<108;p++){
                        button[p].move(button[p].x(),button[p].y()-19);
                    }
                }
            }

        }


        turn++;
        turn=turn%4;
        while(players[turn].win==1){
            turn++;
            turn=turn%4;
        }

        if(turn==0)                                 //更改出牌提示
            this->setturn("玩家1出牌");
        else if(turn==1)
            this->setturn("玩家2出牌");
        else if(turn==2)
            this->setturn("玩家3出牌");
        else
            this->setturn("玩家4出牌");

        nowtype=0;
        now.number=0;

        for(int i=0;i<27;i++){
            now.decor[i]=0;
            now.size[i]=0;
            now.szz[i]=0;
        }

    }



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
