#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<int, std::string> dic;

    dic[0] = "cero";
    dic[1] = "uno";
    dic[2] = "dos";
    dic[5] = "cinco";
    dic[10] = "diez";

    std::cout << dic.size() << "\n";
    std::cout << dic[5] << "\n";
    std::cout << dic.count(5) << "\n";
    std::cout << dic[3] << "\n";
    std::cout << dic.size() << "\n";

    return 0;
}