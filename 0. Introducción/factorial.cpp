#include "factorial.h"

int fact(int n)
{
    int r = 1;
    for (int i = 1; i <= n; ++i) {
        r *= i;
    }
    return r;
}
