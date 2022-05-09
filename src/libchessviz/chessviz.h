#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readNumber(char a);
int readLetter(char a);
int readPiece(char a);
char getfig(int fig);
void fillBoard(char chessviz[8][8]);
void printBoard(char chessviz[8][8]);