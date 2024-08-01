#include <stdio.h>
#include <stdlib.h>

void up(NUM *p){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (p->num[j][i] != 0){
                for (int k = j; k > 0; k--){
                    if (p->num[k - 1][i] == p->num[k][i]){
                        p->num[k - 1][i] = p->num[k - 1][i] << 1;
                        p->num[k][i] = 0;
                    }
                    else if (p->num[k - 1][i] == 0){
                        p->num[k - 1][i] = p->num[k][i];
                        p->num[k][i] = 0;
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
}

void down(NUM *p){
    for (int i = 0; i < 4; i++){
        for (int j = 3; j >= 0; j--){
            if (p->num[j][i] != 0){
                for (int k = j; k < 3; k++){
                    if (p->num[k + 1][i] == p->num[k][i]){
                        p->num[k + 1][i] = p->num[k + 1][i] << 1;
                        p->num[k][i] = 0;
                    }
                    else if (p->num[k + 1][i] == 0){
                        p->num[k + 1][i] = p->num[k][i];
                        p->num[k][i] = 0;
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
}

void left(NUM *p){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (p->num[i][j] != 0){
                for (int k = j; k > 0; k--){
                    if (p->num[i][k - 1] == p->num[i][k]){
                        p->num[i][k - 1] = p->num[i][k - 1] << 1;
                        p->num[i][k] = 0;
                    }
                    else if (p->num[i][k - 1] == 0){
                        p->num[i][k - 1] = p->num[i][k];
                        p->num[i][k] = 0;
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
}

void right(NUM *p){
    for (int i = 0; i < 4; i++){
        for (int j = 3; j >= 0; j--){
            if (p->num[i][j] != 0){
                for (int k = j; k < 3; k++){
                    if (p->num[i][k + 1] == p->num[i][k]){
                        p->num[i][k + 1] = p->num[i][k + 1] << 1;
                        p->num[i][k] = 0;
                    }
                    else if (p->num[i][k + 1] == 0){
                        p->num[i][k + 1] = p->num[i][k];
                        p->num[i][k] = 0;
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
}

void move_boad(NUM *p, int direction){
    while (1){
        printf("↑:1 ↓:2 ←:3 →:4\n");
        printf("Huw to move?\n");
        scanf("%d", &direction);
        switch (direction){
            case 1:
                up(p);
            break;
            case 2:
                down(p);
            break;
            case 3:
                left(p);
            break;
            case 4:
                right(p);
            break;
            default:
                continue;
            break;
        }
        break;
    }
}