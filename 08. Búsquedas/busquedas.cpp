#include <algorithm>
#include <iostream>
#include <vector>

// Complejidad: O(N)
template<typename T>
int sequential_search(const std::vector<T>& values, const T& target)
{
    for (int i = 0; i < values.size(); ++i) {
        if (target == values[i]) {
            return i;
        }
    }
    return -1;
}

// Complejidad: O(log N)
template<typename T>
int binary_search(const std::vector<T>& values, const T& target)
{
    int min = 0;
    int max = values.size() - 1;

    while (min <= max) {
        int mid = min + (max - min) / 2;  // Equivalente a: (min + max) / 2
                                          // pero sin desbordar
        if (target < values[mid]) {
            max = mid - 1;
        } else if (values[mid] < target) {
            min = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main()
{
    std::vector<std::string> v {
        "enero", "febrero", "marzo",
        "abril", "mayo", "junio",
        "julio", "agosto", "septiembre",
        "octubre", "noviembre", "diciembre"
    };

    std::cout << sequential_search(v, std::string("octubre")) << "\n";
    std::cout << sequential_search(v, std::string("postyule")) << "\n";

    std::sort(v.begin(), v.end());

    std::cout << binary_search(v, std::string("octubre")) << "\n";
    std::cout << binary_search(v, std::string("postyule")) << "\n";

    return 0;
}
