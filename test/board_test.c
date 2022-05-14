#include <libchessviz/chessviz.h>

#include <ctest.h>

CTEST(arithmetic_suite, simple_sum)
{
    // Given
    const char a = '1';

    // When
    const int result = readNumber(a);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);

    char chessviz[8][8];
    fillBoard(chessviz);

    ASSERT_EQUAL(0, dvig(chessviz, 1, 4, 2, 4, 4));
}
CTEST(chessviz, dvig)
{
    char chessviz[8][8];
    fillBoard(chessviz);

    ASSERT_EQUAL(0, dvig(chessviz, 1, 4, 2, 4, 4));
}

CTEST(chessviz, readInput1)
{
    char chessviz[8][8];
    fillBoard(chessviz);
    char str[20] = "e2-e4";
    ASSERT_EQUAL(0, readInput(str, chessviz, 0));
}

CTEST(chessviz, readInput2)
{
    char chessviz[8][8];
    fillBoard(chessviz);   
    char str[20] = "qe2-e4";
    ASSERT_EQUAL(1, readInput(str, chessviz, 0));
}
CTEST(chessviz, readInput3)
{
    char chessviz[8][8];
    fillBoard(chessviz);   
    char str[20] = "ze2-e4";
    ASSERT_EQUAL(2, readInput(str, chessviz, 0));
}
CTEST(chessviz, readInput4)
{
    char chessviz[8][8];
    fillBoard(chessviz);   
    char str[20] = "Ke2-e4";
    ASSERT_EQUAL(5, readInput(str, chessviz, 0));
}
CTEST(chessviz, readInput5)
{
    char chessviz[8][8];
    fillBoard(chessviz);   
    char str[20] = "ey-e4";
    ASSERT_EQUAL(4, readInput(str, chessviz, 0));
}
CTEST(chessviz, readInput6)
{
    char chessviz[8][8];
    fillBoard(chessviz);   
    char str[20] = "e2e4";
    ASSERT_EQUAL(6, readInput(str, chessviz, 0));
}
CTEST(chessviz, readInput7)
{
    char chessviz[8][8];
    fillBoard(chessviz);
    char str[20] = "e2-14";
    ASSERT_EQUAL(7, readInput(str, chessviz, 0));
}
CTEST(chessviz, readInput8)
{
    char chessviz[8][8];
    fillBoard(chessviz);
    char str[20] = "Bc1-e2";
    ASSERT_EQUAL(10, readInput(str, chessviz, 0));
}
CTEST(chessviz, readInput9)
{
    char chessviz[8][8];
    fillBoard(chessviz);
    char str[20] = "Nb1-d2";
    ASSERT_EQUAL(12, readInput(str, chessviz, 0));
}
CTEST(chessviz, readInput10)
{
    char chessviz[8][8];
    fillBoard(chessviz);
    char str[20] = "Nb1xd2";
    ASSERT_EQUAL(13, readInput(str, chessviz, 0));
}
CTEST(chessviz, readInput11)
{
    char chessviz[8][8];
    fillBoard(chessviz);
    char str[20] = "Ra1-a4";
    ASSERT_EQUAL(11, readInput(str, chessviz, 0));
}