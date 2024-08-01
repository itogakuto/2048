#include <stdio.h>

void boad_start(NUM *p){   //ポインタ構造体の使用
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 4; k++){
                p[i].num[j][k] = 0;
            }
        }
        printf("use%d name=", i + 1);
        scanf("%s", p[i].name); //usernameの記述
    }
}

void reset_boad(NUM *p){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            p->num[i][j] = 0;
        }
    }
    printf("user name=");
    scanf("%s", p->name);
}