#include <stdio.h>
#include "struct.c"
#include "boad_setting.c"
#include "boad_move.c"

void show_boad(NUM *p){
    printf("user:%s\n", p->name);   //username表示
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%d", p->num[i][j]);
            if (j + 1 == 4){
                break;
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void randum_evaluation(NUM *p, int *bool){
    int a, b;
    do {
        a = rand() % 4;
        b = rand() % 4;
    } while (p->num[a][b] != 0);
    p->num[a][b] = 2;
    int num = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (p->num[i][j] == 0){
                num = 1;
                break;
            }
        }
        if (num == 1){
            break;
        }
    }
    if (num == 0){
        *bool = 4;
        show_boad(p);
    }
}

void next(int *bool, int *usernum){
    while (1){
        printf("continue:1 change user:2 end:3\n");
        scanf("%d", bool);
        if (*bool == 1){
            break;
        }
        else if (*bool == 2){
            printf("usernum=");
            scanf("%d", usernum);
            break;
        }
        else if (*bool == 3){
            break;
        }
        else if (*bool != 4){
            printf("The number isn't set.\n");
            continue;
        }
    }
}