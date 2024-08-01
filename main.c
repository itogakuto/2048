#include <stdalign.h>
#include <stdio.h>
#include "gamemaster.c"
#define REMAIKE

int main(void)
{
    NUM players[5]; //userごとのboad状態を管理する構造体配列
    int bool;   //判定用
    int usernum;    //player number保持用変数
    int direction;  //方向入力用

    //各userごとのboad状態の初期化
    boad_start(players);
    
    //bool,userの初期化
    usernum = 1;
    bool = 1;

    printf("game start!\n");

    while (1){
        randum_evaluation(&players[usernum - 1], &bool);  //ランダムな箇所に
        //game over表示とリセット
        if (bool == 4){
            printf("game over!\n");
            reset_boad(&players[usernum - 1]);
            randum_evaluation(&players[usernum - 1], &bool); 
        }
        show_boad(&players[usernum - 1]);

        move_boad(&players[usernum - 1], direction);

        #ifdef REMAIKE
            printf("//セーブ機能の追加をしたい。");
        #endif

        show_boad(&players[usernum - 1]);

        next(&bool, &usernum);
        
        if (bool == 3){
            printf("Thank you for playing.\n");
            break;
        }
    }
    return (0);
}