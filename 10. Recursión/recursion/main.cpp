#include <iostream>
#include "intlist.h"
#include "recursion.h"

int main()
{
    IntList a {1, 2, 3, 4};
    IntList b = rest(a);
    IntList c = rest(b);
    IntList d = rest(c);

    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";
    std::cout << d << "\n";

    std::cout << first(d) << "\n";
    std::cout << first(rest(a)) << "\n";
    std::cout << is_empty(rest(d)) << "\n";
    std::cout << is_empty(d) << "\n";
    std::cout << cons(42, a) << "\n";

    std::cout << size(a) << "\n";
    std::cout << cons_end(42, a) << "\n";
    std::cout << sum(a) << "\n";

    std::cout << duplicate(a) << "\n";

    std::cout << last(a) << "\n";

    std::cout << but_last(a) << "\n";
    std::cout << maximum(a) << "\n";

    std::cout << append(a, IntList {5, 6, 7, 8}) << "\n";
    std::cout << append(a, IntList {}) << "\n";

    std::cout << repeat(10, 3) << "\n";

    std::cout << merge(IntList {4, 8, 15, 16, 23, 42}, IntList {1, 2, 5, 7, 8, 10}) << "\n";

    std::cout << insert(16, IntList {4, 8, 15, 23, 42}) << "\n";

    std::cout << insertion_sort(IntList {15, 8, 42, 4, 16, 23}) << "\n";

    return 0;
}
