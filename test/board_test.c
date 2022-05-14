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

    ASSERT_EQUAL(0,dvig(chessviz,1,4,2,4,4));
}
CTEST(chessviz, dvig)
{  char chessviz[8][8];
    fillBoard(chessviz);

    ASSERT_EQUAL(0,dvig(chessviz,1,4,2,4,4));
}