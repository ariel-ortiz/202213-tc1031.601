#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    std::vector<int> a;
    std::vector<std::string> b {
        "lunes", "martes", "miércoles",
        "jueves", "viernes", "sábado",
        "domingo"};

    a.reserve(10);
    b.reserve(10);

    std::cout << a.capacity() << "\n";
    for (int i = 0; i < a.size(); ++i) {
        std::cout << i << " " << a[i] << "\n";
    }


    std::cout << b.capacity() << "\n";
    for (int i = 0; i < b.size(); ++i) {
        std::cout << i << " " << b[i] << "\n";
    }

    b.push_back("a");
    std::cout << b.size() << " " << b.capacity() << "\n";

    b.push_back("b");
    std::cout << b.size() << " " << b.capacity() << "\n";

    b.push_back("c");
    std::cout << b.size() << " " << b.capacity() << "\n";

    b.push_back("d");
    std::cout << b.size() << " " << b.capacity() << "\n";

    for (int i = 0; i < 10; ++i) {
        b.push_back("*");
    }

    std::cout << b.size() << " " << b.capacity() << "\n";

    std::cout << b.at(20) << "\n";

    b.at(20) = "otra cosa";

    std::cout << b.at(20) << "\n";

    std::cout << "\n";

    // for (std::vector<std::string>::iterator it = b.begin(); it != b.end(); ++it) {
    //     std::cout << *it << "\n";
    // }

    // for (auto it = b.begin(); it != b.end(); ++it) {
    //     std::cout << *it << "\n";
    // }

    for (std::string x: b) {
        std::cout << x << "\n";
    }

    std::cout << "\n";

    std::cout << std::boolalpha;

    std::cout << a.empty() << "\n";
    std::cout << b.empty() << "\n";

    b.insert(b.begin() + 1, "nada");
    std::cout << b.at(0) << "\n";
    std::cout << b.at(1) << "\n";
    std::cout << b.at(2) << "\n";

    b.erase(b.begin() + 3);

    std::cout << b.at(3) << "\n";

    return 0;
}