#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

struct Country {
    std::string name;
    int gold;
    int silver;
    int bronze;
};

void read_file(const std::string& file_name, std::vector<Country>& values)
{
    std::ifstream file(file_name); // input file stream

    if (file.fail()) {
        std::cerr << "Error when trying to open file: " << file_name << "\n";
        exit(1);
    }

    std::string line;
    while (getline(file, line)) {
        Country c;
        std::istringstream input(line);
        input >> c.name;
        input >> c.gold;
        input >> c.silver;
        input >> c.bronze;
        values.push_back(c);
    }
    file.close();
}

bool compare_countries(const Country& a, const Country& b)
{
    if (a.gold != b.gold) {
        return a.gold > b.gold;
    }
    if (a.silver != b.silver) {
        return a.silver > b.silver;
    }
    if (a.bronze != b.bronze) {
        return a.bronze > b.bronze;
    }
    return a.name < b.name;
}

void print_result(const std::vector<Country>& values)
{
    for (Country c : values) {
        std::cout
            << std::setw(13) << std::left << c.name << " "
            << std::setw(2) << std::right << c.gold << " "
            << std::setw(2) << c.silver << " "
            << std::setw(2) << c.bronze << "\n";
    }
}

int main(int argc, char* argv[])
{
    // for (int i = 0; i < argc; ++i) {
    //     std::cout << i << " " << argv[i] << "\n";
    // }

    if (argc != 2) {
        std::cerr << "Please specify the name of the input file.\n";
        exit(1);
    }

    std::string file_name = argv[1];
    std::vector<Country> country_values;
    read_file(file_name, country_values);
    std::sort(country_values.begin(), country_values.end(), compare_countries);
    print_result(country_values);

    return 0;
}