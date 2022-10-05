#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

const int max_value = 1000;

// Complejidad: O(N)
void fill_random(std::vector<int>& values, int max_value)
{
    std::srand(0);
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = std::rand() % max_value;
    }
}

// Complejidad: O(N^2)
void selection_sort(std::vector<int>& values)
{
    for (int i = 0; i < values.size() - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < values.size(); ++j) {
            if (values[j] < values[min_index]) {
                min_index = j;
            }
        }
        std::swap(values[i], values[min_index]);
    }
}

int main()
{
    std::vector<int> v(20'000);

    fill_random(v, max_value);

    // for (int item: v) {
    //     std::cout << item << " ";
    // }
    // std::cout << "\n";

    std::cout << std::is_sorted(v.begin(), v.end()) << "\n";

    auto start = std::chrono::high_resolution_clock::now();
    selection_sort(v);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(
            stop - start);
    double total_time = duration.count() / 1000000.0;

    std::cout << std::is_sorted(v.begin(), v.end()) << "\n";
    std::cout << total_time << "\n";

    // for (int item: v) {
    //     std::cout << item << " ";
    // }
    // std::cout << "\n";

    return 0;
}
