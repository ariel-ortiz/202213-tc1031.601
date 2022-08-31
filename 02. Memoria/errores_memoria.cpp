#include <iostream>

int main()
{
    // int x = 5;
    // int* p = nullptr;

    // std::cout << *p << "\n";

    int a[10];

    a[9] = 7;
    // a[10] = 8;

    std::cout << a[9] << "\n";
    std::cout << a[1000] << "\n";

    return 0;
}
