#include "mainwindow.h"
#include "card.h"
#include "play.h"
#include <QApplication>
#include <ctime>
#include <QPushButton>
#include <QDebug>



void startgame(MainWindow *w,QPushButton *button,int *location,int &turn){


    srand((int)time(0));
    for(int i=0;i<108;i++){
        location[i]=rand()%108;
        for(int p=0;p<i;p++){
            if(location[p]==location[i]){
                i--;
                break;
            }
        }
    }

    card static poke[108];                             //创建扑克牌数组
    w->poke=poke;

    for(int i=0;i<8;i++)
        poke[i].paimian="A";
    for(int i=8;i<16;i++)
        poke[i].paimian="2";
    for(int i=16;i<24;i++)
        poke[i].paimian="3";
    for(int i=24;i<32;i++)
        poke[i].paimian="4";
    for(int i=32;i<40;i++)
        poke[i].paimian="5";
    for(int i=40;i<48;i++)
        poke[i].paimian="6";
    for(int i=48;i<56;i++)
        poke[i].paimian="7";
    for(int i=56;i<64;i++)
        poke[i].paimian="8";
    for(int i=64;i<72;i++)
        poke[i].paimian="9";
    for(int i=72;i<80;i++)
        poke[i].paimian="10";
    for(int i=80;i<88;i++)
        poke[i].paimian="J";
    for(int i=88;i<96;i++)
        poke[i].paimian="Q";
    for(int i=96;i<104;i++)
        poke[i].paimian="K";
    for(int i=104;i<106;i++)
        poke[i].paimian="小王";
    for(int i=106;i<108;i++)
        poke[i].paimian="大王";






    for(int i=0;i<108;i++){
        if(i<104){
            if(i%8==0||i%8==1)                         //记录花色
                poke[i].decor=1;
            else if(i%8==2||i%8==3)
                poke[i].decor=2;
            else if(i%8==4||i%8==5)
                poke[i].decor=3;
            else
                poke[i].decor=4;
        }


        poke[i].loc=location[i];
        if(poke[i].loc>53)
            poke[i].hs=1;
    }

//牌面：2 ,3 ,4 ,5 ,6 ,7 ,9 ,10,J ,Q ,K ,A ,8 ,小鬼,大鬼
//大小：1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10,11,12,13,14 ,15
    int si[108]={12,12,12,12,12,12,12,12,1,1,1,1,1,1,1,1,
                 2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,
                 4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,
                 6,6,6,6,6,6,6,6,13,13,13,13,13,13,13,13,
                 7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,
                 9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,
                 11,11,11,11,11,11,11,11,14,14,15,15};

    for(int i=0;i<108;i++){                            //给扑克分配大小
        poke[i].size=si[i];
    }

    for(int i=0;i<104;i++){                           //记录排面数字，用于判断顺子
        poke[i].szz=i/8+1;
    }
    for(int i=104;i<108;i++){
        poke[i].szz=99;
    }


    for(int i=0;i<108;i++){
        for(int p=0;p<108;p++){
            if(poke[p].loc==i){
                w->find[i]=p;
                break;
            }
        }
    }



    for(int i=0;i<108;i++){                          //给每副手牌排序
        for(int p=0;p<26;p++){
            if(poke[w->find[p]].size<poke[w->find[p+1]].size){
                int a;
                a=poke[w->find[p+1]].loc;
                poke[w->find[p+1]].loc=poke[w->find[p]].loc;
                poke[w->find[p]].loc=a;
                a=w->find[p];
                w->find[p]=w->find[p+1];
                w->find[p+1]=a;
            }
        }
        for(int p=27;p<53;p++){
            if(poke[w->find[p]].size<poke[w->find[p+1]].size){
                int a;
                a=poke[w->find[p+1]].loc;
                poke[w->find[p+1]].loc=poke[w->find[p]].loc;
                poke[w->find[p]].loc=a;
                a=w->find[p];
                w->find[p]=w->find[p+1];
                w->find[p+1]=a;
            }
        }
        for(int p=54;p<80;p++){
            if(poke[w->find[p]].size<poke[w->find[p+1]].size){
                int a;
                a=poke[w->find[p+1]].loc;
                poke[w->find[p+1]].loc=poke[w->find[p]].loc;
                poke[w->find[p]].loc=a;
                a=w->find[p];
                w->find[p]=w->find[p+1];
                w->find[p+1]=a;
            }
        }
        for(int p=81;p<107;p++){
            if(poke[w->find[p]].size<poke[w->find[p+1]].size){
                int a;
                a=poke[w->find[p+1]].loc;
                poke[w->find[p+1]].loc=poke[w->find[p]].loc;
                poke[w->find[p]].loc=a;
                a=w->find[p];
                w->find[p]=w->find[p+1];
                w->find[p+1]=a;
            }
        }
    }

    for(int i=0;i<108;i++){
        poke[i].setxy();
    }


    for(int i=0;i<108;i++){
        button[i].setParent(w);
        if(i<27){                                      //创建单击动画
            QObject::connect(&button[i],&QPushButton::pressed,
                             [=]{
                if(poke[w->find[i]].up==0){
                    button[i].move(button[i].x(),button[i].y()+20);
                    poke[w->find[i]].up=1;
                }
                else{
                    button[i].move(button[i].x(),button[i].y()-20);
                    poke[w->find[i]].up=0;
                }
            });
        }
        else if(i<54){
            QObject::connect(&button[i],&QPushButton::pressed,
                             [=]{
                if(poke[w->find[i]].up==0){
                    button[i].move(button[i].x(),button[i].y()-20);
                    poke[w->find[i]].up=1;
                }
                else{
                    button[i].move(button[i].x(),button[i].y()+20);
                    poke[w->find[i]].up=0;
                }
            });
        }
        else if(i<81){
            QObject::connect(&button[i],&QPushButton::pressed,
                             [=]{
                if(poke[w->find[i]].up==0){
                    button[i].move(button[i].x()+20,button[i].y());
                    poke[w->find[i]].up=1;
                }
                else{
                    button[i].move(button[i].x()-20,button[i].y());
                    poke[w->find[i]].up=0;
                }
            });
        }
        else{
            QObject::connect(&button[i],&QPushButton::pressed,
                             [=]{
                if(poke[w->find[i]].up==0){
                    button[i].move(button[i].x()-20,button[i].y());
                    poke[w->find[i]].up=1;
                }
                else{
                    button[i].move(button[i].x()+20,button[i].y());
                    poke[w->find[i]].up=0;
                }
            });
        }       


        if(i<54){                                                   //画按钮
            button[i].setMaximumSize(90,135);
            button[i].setMinimumSize(90,135);
        }
        else{
            button[i].setMaximumSize(135,90);
            button[i].setMinimumSize(135,90);
        }
        for(int p=0;p<108;p++){
            if(poke[p].loc==i){
                button[i].move(poke[p].x,poke[p].y);
                break;
            }
        }
    }


    QPushButton static deal,skip;                          //设置出牌，跳过按钮
    deal.setParent(w);
    skip.setParent(w);
    deal.setText("出牌");
    skip.setText("不出");
    deal.setGeometry(450,400,100,35);
    skip.setGeometry(610,400,100,35);
    //########################################################################################################
    //########################################################################################################







    turn=0;


    if(turn==0)
        w->setturn("玩家1出牌");
    else if(turn==1)
        w->setturn("玩家2出牌");
    else if(turn==2)
        w->setturn("玩家3出牌");
    else
        w->setturn("玩家4出牌");






    QObject::connect(&skip,&QPushButton::clicked,w,w->skip);




    QObject::connect(&deal,&QPushButton::clicked,w,w->chupai);               //单击出牌按钮后







//########################################################################################################
//########################################################################################################


    if(poke[0].hs==0)                                       //插入图片
        button[poke[0].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/1.png);}");
    else
        button[poke[0].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/1.png);}");

    if(poke[1].hs==0)
        button[poke[1].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/1.png);}");
    else
        button[poke[1].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/1.png);}");

    if(poke[2].hs==0)
        button[poke[2].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/2.png);}");
    else
        button[poke[2].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/2.png);}");

    if(poke[3].hs==0)
        button[poke[3].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/2.png);}");
    else
        button[poke[3].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/2.png);}");

    if(poke[4].hs==0)
        button[poke[4].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/3.png);}");
    else
        button[poke[4].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/3.png);}");

    if(poke[5].hs==0)
        button[poke[5].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/3.png);}");
    else
        button[poke[5].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/3.png);}");

    if(poke[6].hs==0)
        button[poke[6].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/4.png);}");
    else
        button[poke[6].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/4.png);}");

    if(poke[7].hs==0)
        button[poke[7].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/4.png);}");
    else
        button[poke[7].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/4.png);}");

    if(poke[8].hs==0)
        button[poke[8].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/5.png);}");
    else
        button[poke[8].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/5.png);}");

    if(poke[9].hs==0)
        button[poke[9].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/5.png);}");
    else
        button[poke[9].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/5.png);}");

    if(poke[10].hs==0)
        button[poke[10].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/6.png);}");
    else
        button[poke[10].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/6.png);}");

    if(poke[11].hs==0)
        button[poke[11].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/6.png);}");
    else
        button[poke[11].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/6.png);}");

    if(poke[12].hs==0)
        button[poke[12].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/7.png);}");
    else
        button[poke[12].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/7.png);}");

    if(poke[13].hs==0)
        button[poke[13].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/7.png);}");
    else
        button[poke[13].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/7.png);}");

    if(poke[14].hs==0)
        button[poke[14].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/8.png);}");
    else
        button[poke[14].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/8.png);}");

    if(poke[15].hs==0)
        button[poke[15].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/8.png);}");
    else
        button[poke[15].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/8.png);}");

    if(poke[16].hs==0)
        button[poke[16].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/9.png);}");
    else
        button[poke[16].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/9.png);}");

    if(poke[17].hs==0)
        button[poke[17].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/9.png);}");
    else
        button[poke[17].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/9.png);}");

    if(poke[18].hs==0)
        button[poke[18].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/10.png);}");
    else
        button[poke[18].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/10.png);}");

    if(poke[19].hs==0)
        button[poke[19].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/10.png);}");
    else
        button[poke[19].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/10.png);}");

    if(poke[20].hs==0)
        button[poke[20].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/11.png);}");
    else
        button[poke[20].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/11.png);}");

    if(poke[21].hs==0)
        button[poke[21].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/11.png);}");
    else
        button[poke[21].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/11.png);}");

    if(poke[22].hs==0)
        button[poke[22].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/12.png);}");
    else
        button[poke[22].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/12.png);}");

    if(poke[23].hs==0)
        button[poke[23].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/12.png);}");
    else
        button[poke[23].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/12.png);}");

    if(poke[24].hs==0)
        button[poke[24].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/13.png);}");
    else
        button[poke[24].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/13.png);}");

    if(poke[25].hs==0)
        button[poke[25].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/13.png);}");
    else
        button[poke[25].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/13.png);}");

    if(poke[26].hs==0)
        button[poke[26].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/14.png);}");
    else
        button[poke[26].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/14.png);}");

    if(poke[27].hs==0)
        button[poke[27].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/14.png);}");
    else
        button[poke[27].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/14.png);}");

    if(poke[28].hs==0)
        button[poke[28].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/15.png);}");
    else
        button[poke[28].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/15.png);}");

    if(poke[29].hs==0)
        button[poke[29].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/15.png);}");
    else
        button[poke[29].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/15.png);}");

    if(poke[30].hs==0)
        button[poke[30].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/16.png);}");
    else
        button[poke[30].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/16.png);}");

    if(poke[31].hs==0)
        button[poke[31].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/16.png);}");
    else
        button[poke[31].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/16.png);}");

    if(poke[32].hs==0)
        button[poke[32].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/17.png);}");
    else
        button[poke[32].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/17.png);}");

    if(poke[33].hs==0)
        button[poke[33].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/17.png);}");
    else
        button[poke[33].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/17.png);}");

    if(poke[34].hs==0)
        button[poke[34].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/18.png);}");
    else
        button[poke[34].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/18.png);}");

    if(poke[35].hs==0)
        button[poke[35].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/18.png);}");
    else
        button[poke[35].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/18.png);}");

    if(poke[36].hs==0)
        button[poke[36].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/19.png);}");
    else
        button[poke[36].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/19.png);}");

    if(poke[37].hs==0)
        button[poke[37].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/19.png);}");
    else
        button[poke[37].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/19.png);}");

    if(poke[38].hs==0)
        button[poke[38].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/20.png);}");
    else
        button[poke[38].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/20.png);}");

    if(poke[39].hs==0)
        button[poke[39].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/20.png);}");
    else
        button[poke[39].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/20.png);}");

    if(poke[40].hs==0)
        button[poke[40].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/21.png);}");
    else
        button[poke[40].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/21.png);}");

    if(poke[41].hs==0)
        button[poke[41].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/21.png);}");
    else
        button[poke[41].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/21.png);}");

    if(poke[42].hs==0)
        button[poke[42].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/22.png);}");
    else
        button[poke[42].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/22.png);}");

    if(poke[43].hs==0)
        button[poke[43].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/22.png);}");
    else
        button[poke[43].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/22.png);}");

    if(poke[44].hs==0)
        button[poke[44].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/23.png);}");
    else
        button[poke[44].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/23.png);}");

    if(poke[45].hs==0)
        button[poke[45].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/23.png);}");
    else
        button[poke[45].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/23.png);}");

    if(poke[46].hs==0)
        button[poke[46].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/24.png);}");
    else
        button[poke[46].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/24.png);}");

    if(poke[47].hs==0)
        button[poke[47].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/24.png);}");
    else
        button[poke[47].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/24.png);}");

    if(poke[48].hs==0)
        button[poke[48].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/25.png);}");
    else
        button[poke[48].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/25.png);}");

    if(poke[49].hs==0)
        button[poke[49].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/25.png);}");
    else
        button[poke[49].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/25.png);}");

    if(poke[50].hs==0)
        button[poke[50].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/26.png);}");
    else
        button[poke[50].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/26.png);}");

    if(poke[51].hs==0)
        button[poke[51].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/26.png);}");
    else
        button[poke[51].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/26.png);}");

    if(poke[52].hs==0)
        button[poke[52].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/27.png);}");
    else
        button[poke[52].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/27.png);}");

    if(poke[53].hs==0)
        button[poke[53].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/27.png);}");
    else
        button[poke[53].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/27.png);}");

    if(poke[54].hs==0)
        button[poke[54].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/28.png);}");
    else
        button[poke[54].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/28.png);}");

    if(poke[55].hs==0)
        button[poke[55].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/28.png);}");
    else
        button[poke[55].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/28.png);}");

    if(poke[56].hs==0)
        button[poke[56].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/29.png);}");
    else
        button[poke[56].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/29.png);}");

    if(poke[57].hs==0)
        button[poke[57].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/29.png);}");
    else
        button[poke[57].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/29.png);}");

    if(poke[58].hs==0)
        button[poke[58].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/30.png);}");
    else
        button[poke[58].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/30.png);}");

    if(poke[59].hs==0)
        button[poke[59].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/30.png);}");
    else
        button[poke[59].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/30.png);}");

    if(poke[60].hs==0)
        button[poke[60].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/31.png);}");
    else
        button[poke[60].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/31.png);}");

    if(poke[61].hs==0)
        button[poke[61].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/31.png);}");
    else
        button[poke[61].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/31.png);}");

    if(poke[62].hs==0)
        button[poke[62].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/32.png);}");
    else
        button[poke[62].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/32.png);}");

    if(poke[63].hs==0)
        button[poke[63].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/32.png);}");
    else
        button[poke[63].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/32.png);}");

    if(poke[64].hs==0)
        button[poke[64].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/33.png);}");
    else
        button[poke[64].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/33.png);}");

    if(poke[65].hs==0)
        button[poke[65].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/33.png);}");
    else
        button[poke[65].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/33.png);}");

    if(poke[66].hs==0)
        button[poke[66].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/34.png);}");
    else
        button[poke[66].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/34.png);}");

    if(poke[67].hs==0)
        button[poke[67].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/34.png);}");
    else
        button[poke[67].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/34.png);}");

    if(poke[68].hs==0)
        button[poke[68].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/35.png);}");
    else
        button[poke[68].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/35.png);}");

    if(poke[69].hs==0)
        button[poke[69].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/35.png);}");
    else
        button[poke[69].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/35.png);}");

    if(poke[70].hs==0)
        button[poke[70].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/36.png);}");
    else
        button[poke[70].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/36.png);}");

    if(poke[71].hs==0)
        button[poke[71].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/36.png);}");
    else
        button[poke[71].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/36.png);}");

    if(poke[72].hs==0)
        button[poke[72].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/37.png);}");
    else
        button[poke[72].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/37.png);}");

    if(poke[73].hs==0)
        button[poke[73].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/37.png);}");
    else
        button[poke[73].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/37.png);}");

    if(poke[74].hs==0)
        button[poke[74].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/38.png);}");
    else
        button[poke[74].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/38.png);}");

    if(poke[75].hs==0)
        button[poke[75].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/38.png);}");
    else
        button[poke[75].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/38.png);}");

    if(poke[76].hs==0)
        button[poke[76].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/39.png);}");
    else
        button[poke[76].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/39.png);}");

    if(poke[77].hs==0)
        button[poke[77].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/39.png);}");
    else
        button[poke[77].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/39.png);}");

    if(poke[78].hs==0)
        button[poke[78].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/40.png);}");
    else
        button[poke[78].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/40.png);}");

    if(poke[79].hs==0)
        button[poke[79].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/40.png);}");
    else
        button[poke[79].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/40.png);}");

    if(poke[80].hs==0)
        button[poke[80].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/41.png);}");
    else
        button[poke[80].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/41.png);}");

    if(poke[81].hs==0)
        button[poke[81].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/41.png);}");
    else
        button[poke[81].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/41.png);}");

    if(poke[82].hs==0)
        button[poke[82].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/42.png);}");
    else
        button[poke[82].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/42.png);}");

    if(poke[83].hs==0)
        button[poke[83].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/42.png);}");
    else
        button[poke[83].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/42.png);}");

    if(poke[84].hs==0)
        button[poke[84].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/43.png);}");
    else
        button[poke[84].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/43.png);}");

    if(poke[85].hs==0)
        button[poke[85].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/43.png);}");
    else
        button[poke[85].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/43.png);}");

    if(poke[86].hs==0)
        button[poke[86].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/44.png);}");
    else
        button[poke[86].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/44.png);}");

    if(poke[87].hs==0)
        button[poke[87].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/44.png);}");
    else
        button[poke[87].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/44.png);}");

    if(poke[88].hs==0)
        button[poke[88].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/45.png);}");
    else
        button[poke[88].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/45.png);}");

    if(poke[89].hs==0)
        button[poke[89].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/45.png);}");
    else
        button[poke[89].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/45.png);}");

    if(poke[90].hs==0)
        button[poke[90].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/46.png);}");
    else
        button[poke[90].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/46.png);}");

    if(poke[91].hs==0)
        button[poke[91].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/46.png);}");
    else
        button[poke[91].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/46.png);}");

    if(poke[92].hs==0)
        button[poke[92].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/47.png);}");
    else
        button[poke[92].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/47.png);}");

    if(poke[93].hs==0)
        button[poke[93].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/47.png);}");
    else
        button[poke[93].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/47.png);}");

    if(poke[94].hs==0)
        button[poke[94].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/48.png);}");
    else
        button[poke[94].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/48.png);}");

    if(poke[95].hs==0)
        button[poke[95].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/48.png);}");
    else
        button[poke[95].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/48.png);}");

    if(poke[96].hs==0)
        button[poke[96].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/49.png);}");
    else
        button[poke[96].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/49.png);}");

    if(poke[97].hs==0)
        button[poke[97].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/49.png);}");
    else
        button[poke[97].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/49.png);}");

    if(poke[98].hs==0)
        button[poke[98].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/50.png);}");
    else
        button[poke[98].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/50.png);}");

    if(poke[99].hs==0)
        button[poke[99].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/50.png);}");
    else
        button[poke[99].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/50.png);}");

    if(poke[100].hs==0)
        button[poke[100].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/51.png);}");
    else
        button[poke[100].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/51.png);}");

    if(poke[101].hs==0)
        button[poke[101].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/51.png);}");
    else
        button[poke[101].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/51.png);}");

    if(poke[102].hs==0)
        button[poke[102].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/52.png);}");
    else
        button[poke[102].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/52.png);}");

    if(poke[103].hs==0)
        button[poke[103].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/52.png);}");
    else
        button[poke[103].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/52.png);}");

    if(poke[104].hs==0)
        button[poke[104].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/53.png);}");
    else
        button[poke[104].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/53.png);}");

    if(poke[105].hs==0)
        button[poke[105].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/53.png);}");
    else
        button[poke[105].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/53.png);}");

    if(poke[106].hs==0)
        button[poke[106].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/54.png);}");
    else
        button[poke[106].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/54.png);}");

    if(poke[107].hs==0)
        button[poke[107].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix1/SOURSES/竖/54.png);}");
    else
        button[poke[107].loc].setStyleSheet("QPushButton{border-image:url(:/new/prefix2/SOURSES/横/54.png);}");




}



