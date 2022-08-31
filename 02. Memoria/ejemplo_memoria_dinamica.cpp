#include <iostream>

int main()
{
    int* ptr_int;
    int* array;

    ptr_int = new int(7);
    array = new int[10] {1, 2, 3};

    std::cout << *ptr_int << "\n";
    std::cout << ptr_int << "\n";
    std::cout << array[0] << "\n";
    std::cout << *(array + 0) << "\n";
    std::cout << array[2] << "\n";
    std::cout << *(array + 2) << "\n";

    delete ptr_int;
    delete [] array;

    return 0;
}
