#include <iostream>
#include "linkedlist.h"

int main()
{
    LinkedList<int> my_list;

    my_list.insert_front(7);
    my_list.insert_front(3);
    my_list.insert_front(10);

    std::cout << my_list.size() << "\n";
    std::cout << my_list << "\n";

    std::cout << my_list.remove_front() << "\n";

    std::cout << my_list.size() << "\n";
    std::cout << my_list << "\n";

    my_list.insert_back(15);
    my_list.insert_back(16);
    my_list.insert_back(23);

    std::cout << my_list.size() << "\n";
    std::cout << my_list << "\n";

    LinkedList<std::string> lista_str {"enero", "febrero", "marzo", "abril",
        "mayo", "junio", "julio", "agosto", "septiembre", "octubre",
        "noviembre", "diciembre"
    };

    std::cout << lista_str.size() << "\n";
    std::cout << lista_str << "\n";

    std::cout << "\n";

    // for (auto it = lista_str.begin(); it != lista_str.end(); ++it) {
    //     std::cout << *it << "\n";
    // }

    for (std::string s : lista_str) {
        std::cout << s << "\n";
    }


    return 0;
}
