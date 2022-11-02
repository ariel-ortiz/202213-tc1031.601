#include <iostream>

int main()
{
    std::hash<std::string> hash_str;
    std::hash<int> hash_int;
    std::hash<float> hash_float;

    std::cout << hash_str("abc") << "\n";
    std::cout << hash_str("ab") << "\n";

    std::string s = "abc";
    std::cout << hash_str(s) << "\n";

    std::cout << hash_int(42) << "\n";
    std::cout << hash_float(42) << "\n";

    return 0;
}