#pragma once
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readNumber(char a);
int readLetter(char a);
int readPiece(char a);
char getfig(int fig);
void fillBoard(char chessviz[8][8]);
void printBoard(char chessviz[8][8]);
int readInput(char str[20], char chessviz[8][8], int i);
int dvig(char chessviz[8][8], int ternTipe, int x1, int y1, int x2, int y2);
int moveFig(
        char chessviz[8][8],
        int fig,
        int ternTipe,
        int x1,
        int y1,
        int x2,
        int y2);
