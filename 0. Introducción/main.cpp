#include <iostream>
#include "factorial.h"

int main()
{
    std::cout << "Hola\n";
    int n = 5;
    int x = fact(n);
    std::cout << "El factorial de " << n << " es " << x << "\n";
    std::cout << "Esto se acabó\n";
    return 0;
}
