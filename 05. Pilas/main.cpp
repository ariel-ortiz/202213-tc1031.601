#include <iostream>
#include <vector>
#include "stack.h"

// Complejidad: O(N)
bool is_palindrome(const std::string word)
{
    Stack<char> s(word.size());

    for (char c : word) {
        s.push(c);
    }

    for (char c : word) {
        if (c != s.pop()) {
            return false;
        }
    }

    return true;
}

int main()
{
    // Stack<int> a(5);
    // a.push(1);
    // a.push(7);
    // a.push(15);
    // a.push(16);
    // a.push(23);
    // std::cout << a.pop() << "\n";
    // std::cout << a.peek() << "\n";
    // std::cout << a.size() << "\n";
    // std::cout << a.capacity() << "\n";

    std::vector<std::string> dias {
        "lunes", "martes", "miércoles",
        "jueves", "viernes", "sábado",
        "domingo"
    };

    for (std::string s : dias) {
        std::cout << s << " ";
    }

    std::cout << "\n";

    Stack<std::string> my_stack(dias.size());

    for (std::string s : dias) {
        my_stack.push(s);
    }

    dias.clear();

    while (not my_stack.is_empty()) {
        dias.push_back(my_stack.pop());
    }

    for (std::string s : dias) {
        std::cout << s << " ";
    }

    std::cout << "\n";

    std::cout << is_palindrome("anitalavalatina") << "\n";
    std::cout << is_palindrome("anitalavalaloza") << "\n";

    return 0;
}
