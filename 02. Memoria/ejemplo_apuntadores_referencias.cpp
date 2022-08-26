#include <iostream>

const int x = 6;

void pruebita_1(int x, int y) // paso por valor
{
    std::cout << "x = " << x << ", y = " << y << "\n";
    int t = x;
    x = y;
    y = t;
    std::cout << "x = " << x << ", y = " << y << "\n";
}

void pruebita_2(int& x, int& y) // paso por referencia
{
    std::cout << "x = " << x << ", y = " << y << "\n";
    int t = x;
    x = y;
    y = t;
    std::cout << "x = " << x << ", y = " << y << "\n";
}


int main()
{
    int a = 7;
    int* b = &a;
    int** c = &b;
    int*** d = &c;
    int& e = a;

    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << *b << "\n";
    ++(*b);
    std::cout << a << "\n";
    (**c) += 10;
    std::cout << ***d << "\n";

    std::cout << e << "\n";
    std::cout << &e << "\n";

    ++a;
    std::cout << e << "\n";

    int f = 5;
    int g = 8;
    std::cout << "f = " << f << ", g = " << g << "\n";
    pruebita_1(f, g);
    std::cout << "f = " << f << ", g = " << g << "\n";
    pruebita_2(f, g);
    std::cout << "f = " << f << ", g = " << g << "\n";

    return 0;
}