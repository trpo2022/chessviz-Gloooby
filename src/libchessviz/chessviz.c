#include <libchessviz/chessviz.h>
//#include "chessviz.h"

int readNumber(char a)
{
    switch (a) {
    case '1':
        return 0;
    case '2':
        return 1;
    case '3':
        return 2;
    case '4':
        return 3;
    case '5':
        return 4;
    case '6':
        return 5;
    case '7':
        return 6;
    case '8':
        return 7;
    default:
        return -1;
    }
}

int readLetter(char a)
{
    switch (a) {
    case 'a':
        return 0;
    case 'b':
        return 1;
    case 'c':
        return 2;
    case 'd':
        return 3;
    case 'e':
        return 4;
    case 'f':
        return 5;
    case 'g':
        return 6;
    case 'h':
        return 7;
    default:
        return -1;
    }
}
int readPiece(char a)
{
    switch (a) {
    case 'K':
        return 1;
    case 'Q':
        return 2;
    case 'R':
        return 3;
    case 'B':
        return 4;
    case 'N':
        return 5;
    default:
        return -1;
    }
}
char getfig(int fig)
{
    char a;
    switch (fig) {
    case 1:
        a = 'K';
        return a;
    case 2:
        a = 'Q';
        return a;
    case 3:
        a = 'R';
        return a;
    case 4:
        a = 'B';
        return a;
    case 5:
        a = 'N';
        return a;
    case 6:
        a = 'P';
        return a;
    default:
        a = ' ';
        return a;
    }
}
void fillBoard(char chessviz[8][8])
{
    char mas[8][8] = {
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    };
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chessviz[i][j] = mas[i][j];
        }
    }
}
void printBoard(char chessviz[8][8])
{
    for (int i = 7; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%c ", chessviz[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (int j = 0; j < 8; j++) {
        printf("%c ", j + 97);
    }
    printf("\n");
}
void dvig(char chessviz[8][8], int ternTipe, int x1, int y1, int x2, int y2)
{
    if ((chessviz[y2][x2] == ' ' && ternTipe == 1)
        || (chessviz[y2][x2] != ' ' && ternTipe == 2)) {
        if (ternTipe == 2) {
            if ((isupper(chessviz[y1][x1]) != 0
                 && isupper(chessviz[y2][x2]) == 0)
                || (isupper(chessviz[y1][x1]) == 0
                    && isupper(chessviz[y2][x2]) != 0)) {
                chessviz[y2][x2] = chessviz[y1][x1];
                chessviz[y1][x1] = ' ';
            } else {
                printf("Error - невозиожно взятие союзной фигуры\n");
                return;
            }
        }
        if (ternTipe == 1) {
            chessviz[y2][x2] = chessviz[y1][x1];
            chessviz[y1][x1] = ' ';
        }
    } else
        printf("Error - конечная цель не соответствует типу хода\n");
}

int readInput(char str[20], char chessviz[8][8],int i)
{
    int fig, x1, y1, x2, y2;
    int ternTipe;
    int shaxMat;

    fig = readPiece(str[i]);
    if (fig == -1) {
        x1 = readLetter(str[i]);
        if (x1 != -1) {
            fig = 6;
            i++;
        } else {
            if (str[i] == 'q' && i==0) {
                printf("Выход\n");
                return 1;
            }
            printf("Error1\n");
            return 0;
        }
    } else {
        i++;
        x1 = readLetter(str[i]);
        if (x1 == -1) {
            printf("Error2\n");
            return 0;
        }
        i++;
    }
    y1 = readNumber(str[i]);
    if (y1 == -1) {
        printf("Error3\n");
        return 0;
    }
    i++;

    if (tolower(chessviz[y1][x1]) != tolower(getfig(fig))) {
        printf("Неправильный ввод, не указана фигура или указана не та\n");
        return 0;
    }

    switch (str[i]) {
    case '-': {
        ternTipe = 1;
        break;
    }
    case 'x': {
        ternTipe = 2;
        break;
    }
    default: {
        printf("Error\n");
        return 0;
    }
    }

    i++;

    x2 = readLetter(str[i]);
    if (x2 != -1) {
        i++;
    } else {
        printf("Error4\n");
        return 0;
    }

    y2 = readNumber(str[i]);
    if (y2 == -1) {
        printf("Error5\n");
        return 0;
    }
    i++;
    // printf("i-%d,  %ld\n",i, strlen(str));
    switch (str[i]) {
    case '#': {
        i++;
        shaxMat = 1;
        break;
    }
    case '+': {
        i++;
        shaxMat = 2;
        break;
    }
    }
    
    moveFig(chessviz, fig, ternTipe, x1, y1, x2, y2);
    if (shaxMat == 1)
    {
        printf("Кто-то победил\n");
    }
    
    else
    {
    for (int j = i; j < (int)strlen(str); j++) {
        if (str[j] != ' ') {
            printf("Error6\n");

            return 0;
        }
    }
    }
    return 0;
}

int moveFig(
        char chessviz[8][8],
        int fig,
        int ternTipe,
        int x1,
        int y1,
        int x2,
        int y2)
{
    // -------------------ХОДЫ-------------------
    if (fig == 6) { // -----Пешка (p)----
        switch (ternTipe) {
        case 1:
            /* - перемещение */
            if (chessviz[y2][x2] != ' ') {
                printf("Error7\n");
                return 0;
            } else {
                if (x1 == x2 && abs(y2 - y1) <= 2) {
                    chessviz[y2][x2] = chessviz[y1][x1];
                    chessviz[y1][x1] = ' ';
                }
            }
            break;
        case 2:
            /* x  взятие */
            if (chessviz[y2][x2] == ' ') {
                printf("Error8\n");
                return 0;
            } else {
                if (abs(x1 - x2) == 1 && abs(y2 - y1) == 1) {
                    chessviz[y2][x2] = chessviz[y1][x1];
                    chessviz[y1][x1] = ' ';
                }
            }
            break;
        default:
            return 0;
        }
    }

    if (fig == 5) { // ---------Конь (N)----------
        if ((abs(x1 - x2) == 1 && abs(y1 - y2) == 2)
            || (abs(x1 - x2) == 2 && abs(y1 - y2) == 1)) {
            dvig(chessviz, ternTipe, x1, y1, x2, y2);
        } else {
            printf("Error - фигура так не двигается\n");
            return 0;
        }
    }

    if (fig == 4) { // ---------Слон (B)----------
        if (abs(x1 - x2) == abs(y1 - y2)) {
            int xplus = 1, yplus = 1;
            if (x1 > x2)
                xplus = -1;
            if (y1 > y2)
                yplus = -1;

            for (int j = 1; j < abs(x1 - x2); j++) {
                if (chessviz[y1 + yplus * j][x1 + xplus * j] != ' ') {
                    printf("Error - слон не иожет двигаться по клеткам с "
                           "фигурами\n");
                    return 0;
                }
            }
            dvig(chessviz, ternTipe, x1, y1, x2, y2);
        } else {
            printf("Error - фигура так не двигается\n");
            return 0;
        }
    }

    if (fig == 3) { // ---------Ладья (R)----------
        if (((x1 - x2) == 0 && (y1 - y2) != 0)
            || ((x1 - x2) != 0 && (y1 - y2) == 0)) {
            int xplus = 0, yplus = 0;
            if (x1 > x2)
                xplus = -1;
            if (y1 > y2)
                yplus = -1;
            if (x1 < x2)
                xplus = 1;
            if (y1 < y2)
                yplus = 1;

            for (int j = 1; j < abs(x1 - x2) + abs(y1 - y2); j++) {
                if (chessviz[y1 + yplus * j][x1 + xplus * j] != ' ') {
                    printf("Error - Ладья не иожет двигаться по клеткам с "
                           "фигурами\n");
                    return 0;
                }
            }
            dvig(chessviz, ternTipe, x1, y1, x2, y2);
        }
    }

    if (fig == 2) { // ---------Ферзь (Q)----------
        if (((x1 - x2) == 0 && (y1 - y2) != 0)
            || ((x1 - x2) != 0 && (y1 - y2) == 0)
            || (abs(x1 - x2) == abs(y1 - y2))) {
            int xplus = 0, yplus = 0;
            if (x1 > x2)
                xplus = -1;
            if (y1 > y2)
                yplus = -1;
            if (x1 < x2)
                xplus = 1;
            if (y1 < y2)
                yplus = 1;
            int step = 0;
            if (abs(x1 - x2) == 0 || abs(y1 - y2) == 0)
                step = abs(x1 - x2) + abs(y1 - y2);
            else
                step = abs(x1 - x2);

            for (int j = 1; j < step; j++) {
                if (chessviz[y1 + yplus * j][x1 + xplus * j] != ' ') {
                    printf("Error - Ферзь не иожет двигаться по клеткам с "
                           "фигурами\n");
                    return 0;
                }
            }
            dvig(chessviz, ternTipe, x1, y1, x2, y2);
        }
    }

    if (fig == 1) { // ---------Король (K)----------
        if (abs(x1 - x2) <= 1 && abs(y2 - y1) <= 1) {
            dvig(chessviz, ternTipe, x1, y1, x2, y2);
        }
    }
    return 0;
}