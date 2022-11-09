#include <iostream>

long fact(int n)
{
    if (n <= 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}


int main()
{
    std::cout << "5! = " << fact(5) << "\n";
    std::cout << "20! = " << fact(20) << "\n";
    std::cout << "21! = " << fact(21) << "\n";
    std::cout << "-5! = " << fact(-5) << "\n";
    return 0;
}

