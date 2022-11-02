#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set<char> set_char {'a', 'b', 'c'};

    std::cout << set_char.count('c') << "\n";
    std::cout << set_char.count('x') << "\n";

    set_char.insert('x');
    std::cout << set_char.count('x') << "\n";

    std::cout << set_char.erase('a') << "\n";
    std::cout << set_char.count('a') << "\n";
    std::cout << set_char.erase('a') << "\n";

    for (char c : set_char) {
        std::cout << c << ' ';
    }

    std::cout << "\n";

    return 0;
}