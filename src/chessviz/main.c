
#include <libchessviz/chessviz.c>

int main()
{
    char chessviz[8][8];
    /*
    ТипФигуры = 'K=1'Король | 'Q=2'Ферзь | 'R=3'Ладья | 'B=4'Слон | 'N=5'Конь
    | 'P=6'Пешка Поле = /[a-h][1-8]/

    */
    fillBoard(chessviz);

    while (1) {
        printBoard(chessviz);

        char str[20];
        scanf("%s", str);
        int ret = readInput(str, chessviz, 0);
        if (ret != 0) {
            return 0;
        }
    }
    return 0;
}