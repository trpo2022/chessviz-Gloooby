#include <ctype.h>
#include <stdio.h>
int switch1(char a)
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
int switcha(char a)
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
int switchf(char a)
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

int main()
{
    char chessviz[8][8];
    // printf("Hello, World\n");

    /*
    ТипФигуры = 'K=1'Король | 'Q=2'Королева | 'R=3'Ладья | 'B=4'Слон | 'N=5'Конь
    | 'P=6'Пешка Поле = /[a-h][1-8]/

    */
    chessviz[7][0] = 'r';
    chessviz[7][1] = 'n';
    chessviz[7][2] = 'b';
    chessviz[7][3] = 'q';
    chessviz[7][4] = 'k';
    chessviz[7][5] = 'b';
    chessviz[7][6] = 'n';
    chessviz[7][7] = 'r';

    for (int i = 0; i < 8; i++) {
        chessviz[1][i] = 'P';
        chessviz[2][i] = ' ';
        chessviz[3][i] = ' ';
        chessviz[4][i] = ' ';
        chessviz[5][i] = ' ';
        chessviz[6][i] = 'p';
    }

    chessviz[0][0] = 'R';
    chessviz[0][1] = 'N';
    chessviz[0][2] = 'B';
    chessviz[0][3] = 'Q';
    chessviz[0][4] = 'K';
    chessviz[0][5] = 'B';
    chessviz[0][6] = 'N';
    chessviz[0][7] = 'R';

    int gg = 0;
    while (gg <5) {
        gg++;

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

        char str[20];
        scanf("%s", str);
        int i = 0;
        int fig, x1, y1, x2, y2;

        fig = switchf(str[i]);
        if (fig == -1) {
            x1 = switcha(str[i]);
            if (x1 != -1) {
                fig = 6;
                i++;
            } else {
                printf("Error\n");
                return 0;
            }
        } else {
            i++;
            x1 = switcha(str[i]);
            if (x1 == -1) {
                printf("Error\n");
                return 0;
            }
            i++;
        }
        y1 = switch1(str[i]);
        if (y1 == -1) {
            printf("Error\n");
            return 0;
        }
        i++;
        printf("fig - %d; x - %d; y - %d\n", fig, x1, y1);
        // printf("%c\n",chessviz[y][x]);
        // printf("%c\n",getfig(fig));
        if (tolower(chessviz[y1][x1]) == tolower(getfig(fig))) {
            printf("Correct\n");
        } else {
            printf("ErrorN\n");
        }

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
        i++;

        x2 = switcha(str[i]);
        if (x2 != -1) {
            i++;
        } else {
            printf("Error1\n");
            return 0;
        }

        y2 = switch1(str[i]);
        if (y2 == -1) {
            printf("Error3\n");
            return 0;
        }
        i++;

        printf("x - %d; y - %d\n", x2, y2);
        char tmp = chessviz[y2][x2];
        chessviz[y2][x2] = chessviz[y1][x1];
        chessviz[y1][x1] = tmp;
    }
    return 0;
}