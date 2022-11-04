#include <iostream>
#include <unordered_map>

std::string hex(long n)
{
    if (n == 0) {
        return "0";
    }

    std::string result = "";
    std::unordered_map<int, std::string> hex_digits = {
        {0, "0"},  {1, "1"},  {2, "2"},
        {3, "3"},  {4, "4"},  {5, "5"},
        {6, "6"},  {7, "7"},  {8, "8"},
        {9, "9"},  {10, "A"}, {11, "B"},
        {12, "C"}, {13, "D"}, {14, "E"},
        {15, "F"}
    };

    bool is_negative = false;
    if (n < 0) {
        is_negative = true;
        n = -n;
    }

    while (n > 0) {
        int residuo = n % 16;
        result = hex_digits[residuo] + result;
        n /= 16;
    }

    if (is_negative) {
        result = "-" + result;
    }

    return result;
}


int main()
{
    std::cout << hex(28) << "\n";
    std::cout << hex(0) << "\n";
    std::cout << hex(255) << "\n";
    std::cout << hex(1023) << "\n";
    std::cout << hex(3'405'691'582) << "\n";
    std::cout << hex(-666) << "\n";
    std::cout << hex(42.5) << "\n";
    return 0;
}
