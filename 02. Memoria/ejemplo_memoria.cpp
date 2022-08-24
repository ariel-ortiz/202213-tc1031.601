#include <iostream>

int varglobalinit = 50;
int varglobalinit2 = 60;
int varglobalnoinit;

int fun()
{
    return 66;
}

int main()
{
    int varlocalnoinit;
    int varlocalinit = 42;
    int* apuntador = new int(70);

    std::cout << "varglobalinit    = " << varglobalinit << "\n";
    std::cout << "&varglobalinit   = " << &varglobalinit << "\n";
    std::cout << "varglobalinit2.  = " << varglobalinit2 << "\n";
    std::cout << "&varglobalinit2  = " << &varglobalinit2 << "\n";
    std::cout << "varglobalnoinit  = " << varglobalnoinit << "\n";
    std::cout << "&varglobalnoinit = " << &varglobalnoinit << "\n";

    std::cout << "varlocalinit     = " << varlocalinit << "\n";
    std::cout << "&varlocalinit    = " << &varlocalinit << "\n";
    std::cout << "varlocalnoinit   = " << varlocalnoinit << "\n";
    std::cout << "&varlocalnoinit  = " << &varlocalnoinit << "\n";

    std::cout << "Size of int  = " << sizeof(varlocalinit) << "\n";
    std::cout << "Size of int* = " << sizeof(apuntador) << "\n";

    std::cout << "apuntador        = " << apuntador << "\n";
    std::cout << "&apuntador       = " << &apuntador << "\n";
    std::cout << "*apuntador       = " << *apuntador << "\n";

    return 0;
}
