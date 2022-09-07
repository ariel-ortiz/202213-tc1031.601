#include <iostream>
#include "linkedlist.h"

int main()
{
    LinkedList<int> my_list;

    my_list.insert_front(7);
    my_list.insert_front(3);
    my_list.insert_front(10);

    std::cout << my_list.size() << "\n";
    std::cout << my_list.to_string() << "\n";

    std::cout << my_list.remove_front() << "\n";

    std::cout << my_list.size() << "\n";
    std::cout << my_list.to_string() << "\n";

    return 0;
}
