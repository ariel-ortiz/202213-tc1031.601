#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

void print_vector(std::vector<int>& data)
{
    for (int e : data) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

void fill_random(std::vector<int>& values, int max_value)
{
    std::srand(0);
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = std::rand() % max_value;
    }
}

int main()
{
    std::vector<int> v(10'000'000);
    fill_random(v, 1'000);
    std::cout << std::is_sorted(v.begin(), v.end()) << "\n";
    // print_vector(v);

    auto start = std::chrono::high_resolution_clock::now();
    std::sort(v.begin(), v.end());
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(
            stop - start);
    double total_time = duration.count() / 1000000.0;

    std::cout << std::is_sorted(v.begin(), v.end()) << "\n";
    // print_vector(v);
    std::cout << "Tiempo total = " << total_time << " segundos\n";
    return 0;
}