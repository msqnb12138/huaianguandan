#ifndef PLAY_H
#define PLAY_H
#include <QDebug>

class play
{
public:
    int number=0;
    int size[27]={0};
    int decor[27]={0};
    int szz[27]={0};

    int type(){                         //0为未选择牌，11为不存在的牌型
        int type=11;



        if (number==0)
            type=0;
        if (number==1)                  //1为单牌2为对子3为三连
            type=1;
        else if (number==2){
            if(size[0]==size[1])
                type=2;
        }
        else if(number==3){
            if(size[0]==size[1]&&size[0]==size[2])
                type=3;
        }
        else if(number==4){                                               //王炸
            if(size[0]==14&&size[1]==14&&size[2]==15&&size[3]==15){
                type=10;
                number=9;
                return type;
            }
        }

        else if(number==5){           //4为三带二，5为顺子，6为同花顺
            int t4=4;
            int a=size[0];
            int b=0;
            for(int i=1;i<5;i++){
                if(size[i]!=a){
                    b=size[i];
                    break;
                }
            }
            int number1=1,number2=0;
            for(int i=1;i<5;i++){
                if(size[i]!=a&&size[i]!=b){
                    t4=5;
                    break;
                }
                if(size[i]==a)
                    number1++;
                if(size[i]==b)
                    number2++;
            }
            if(t4==4){
                if(number1==3&&number2==2){
                    size[0]=a;
                    return 4;
                }
                else if(number2==3&&number1==2){
                    size[0]=b;
                    return 4;
                }

            }                                           //三带二type4
 //########################################################################################################

            if(szz[0]==szz[1]-1&&szz[1]==szz[2]-1&&szz[2]==szz[3]-1&&szz[3]==szz[4]-1){
                type=5;
                if(szz[0]==1)
                    size[0]=0;
            }

            else if(szz[0]==1&&szz[1]==10&&szz[2]==11&&szz[3]==12&&szz[4]==13){
                type=5;
                size[0]=10;
            }
                                                        //单顺子
//########################################################################################################

            if(type==5){                                //同花顺
                if(decor[0]==decor[1]&&decor[1]==decor[2]&&decor[2]==decor[3]&&decor[3]==decor[4])
                    type=6;
            }
        }
//########################################################################################################

        else if(number==6){                            //三顺或连对
            if(szz[0]==szz[1]&&szz[1]==szz[2]&&szz[3]==szz[2]+1&&szz[3]==szz[4]&&szz[4]==szz[5]){
                type=7;
                if(szz[0]==1)
                    size[0]=0;
            }

            else if(szz[0]==szz[1]&&szz[1]==szz[2]-1&&szz[2]==szz[3]&&szz[3]==szz[4]-1&&szz[4]==szz[5]){
                bool ld=1;
                for(int i=0;i<5;i++){
                    if(size[i]==14||size[i]==15)
                        ld=0;
                }
                if(ld==1){
                    type=8;
                }
                if(szz[0]==1)
                    size[0]=0;
            }

        }

        if(number>=4){
            int zd=1;
            for(int i=0;i<number;i++){
                if(size[i]!=size[0])
                    zd=0;
            }
            if(zd==1)
               type=10;
                                                         //10为炸弹，size[0]储存张数
        }








        return type;
    }




    play();
};

#endif // PLAY_H
