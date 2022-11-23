#include <iostream>
#include <vector>
#include "treeset.h"

void print_value(int x)
{
    std::cout << x << " ";
}

int main()
{
    TreeSet<int> a;
    a.add(50);
    a.add(25);
    a.add(70);
    a.add(10);
    a.add(4);
    a.add(62);
    a.add(19);
    a.add(81);

    a.inorder(print_value);
    std::cout << "\n";

    a.preorder(print_value);
    std::cout << "\n";

    a.postorder(print_value);
    std::cout << "\n";

    a.inorder([&] (int x) { std::cout << x << " "; });
    std::cout << "\n";

    int sum = 0;
    a.postorder([&] (int x) { sum += x; });
    std::cout << "sum = " << sum << "\n";

    int even = 0;
    a.preorder([&] (int x) {
        if (x % 2 == 0) {
            ++even;
        }
    });
    std::cout << "even = " << even << "\n";

    return 0;
}
