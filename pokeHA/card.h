#ifndef CARD_H
#define CARD_H
#include <QPushButton>
#include <QString>

class card
{
public:
    int decor=0;                    //decor:红桃1，方块2，黑桃3，梅花4
    int szz;                        //顺子专用，用于记录排面大小
    int size,loc;
    int x,y;
    bool hs=0;                        //0为竖，1为横
    bool up=0;
    QString paimian;
    bool out=0;                          //0为未打出，1为打出

    void setxy(){
        if(loc<27){
            x=246+loc*23;
            y=25;
        }
        else if(loc<54){
            x=246+(loc-27)*23;
            y=480;
        }
        else if(loc<81){
            x=25;
            y=28+(loc-54)*19;
        }
        else{
            x=1020;
            y=28+(loc-81)*19;
        }
    }




    card();

};

#endif // CARD_H
