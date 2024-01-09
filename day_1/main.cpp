#include <iostream>
#include <fstream>
#include <regex>

enum units {
    zero = 0,
    one = 1,
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7,
    eight = 8,
    nine = 9
};

int main() {
    std::ifstream fin;

    fin.open("input.txt");

    std::string line;

    const std::regex numbers_regex("29lzrxseven");
    std::smatch numbers_match;

    while (getline(fin, line)) {
        std::cout << line << ": " << std::regex_match(line, numbers_regex) << '\n';
    }

	return 0;
}