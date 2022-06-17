#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

int climb_stairs(int n)
{
    int n2 = 1;
    int n1 = 1;
    int tmp = n1;

    while (n > 1)
    {
        tmp = n1;
        n1 += n2;
        n2 = tmp;
        --n;
    }

    return n1;
}

TEST_CASE("Example 1")
{
    CHECK_EQ(climb_stairs(2), 2);
}

TEST_CASE("Example 2")
{
    CHECK_EQ(climb_stairs(3), 3);
}
