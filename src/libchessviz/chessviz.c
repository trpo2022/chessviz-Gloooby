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