#include <ctype.h>
#include <stdio.h>
#include <libchessviz/chessviz.c>
//#include "chessviz.h"

int main()
{
    char chessviz[8][8];
    /*
    ТипФигуры = 'K=1'Король | 'Q=2'Королева | 'R=3'Ладья | 'B=4'Слон | 'N=5'Конь
    | 'P=6'Пешка Поле = /[a-h][1-8]/

    */
    fillBoard(chessviz);

    int gg = 0;
    while (gg < 5) {
        gg++;

        printBoard(chessviz);

        char str[20];
        scanf("%s", str);
        int i = 0;
        int fig, x1, y1, x2, y2;

        fig = readPiece(str[i]);
        if (fig == -1) {
            x1 = readLetter(str[i]);
            if (x1 != -1) {
                fig = 6;
                i++;
            } else {
                if (str[i]=='q')
                {
                    printf("Выход\n");
                    return 0;
                }
                printf("Error\n");
                return 0;
            }
        } else {
            i++;
            x1 = readLetter(str[i]);
            if (x1 == -1) {
                printf("Error\n");
                return 0;
            }
            i++;
        }
        y1 = readNumber(str[i]);
        if (y1 == -1) {
            printf("Error\n");
            return 0;
        }
        i++;
        
        //printf("fig - %d; x - %d; y - %d\n", fig, x1, y1);
        // printf("%c\n",chessviz[y][x]);
        // printf("%c\n",getfig(fig));
        if (tolower(chessviz[y1][x1]) == tolower(getfig(fig))) {
            //printf("Correct\n");
        } else {
            printf("Неправильный ввод, не указана фигура\n");
            fig=-1;
        }
        
        /*
        switch (str[i]) {
        case '-': {
            printf("-\n");
            break;
        }
        case 'x': {
            printf("x\n");
            break;
        }
        default: {
            printf("Error\n");
            return 0;
        }
        }
        */
        i++;

        x2 = readLetter(str[i]);
        if (x2 != -1) {
            i++;
        } else {
            printf("Error1\n");
            return 0;
        }

        y2 = readNumber(str[i]);
        if (y2 == -1) {
            printf("Error3\n");
            return 0;
        }
        i++;

        // printf("x - %d; y - %d\n", x2, y2);
        if (fig == 6) {
            if (x1 == x2 && abs(y2 - y1) <= 2) {
                char tmp = chessviz[y2][x2];
                chessviz[y2][x2] = chessviz[y1][x1];
                chessviz[y1][x1] = tmp;
            }
        }
        fig=-1;
    }
    return 0;
}