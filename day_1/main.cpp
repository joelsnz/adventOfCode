#include <iostream>
#include <fstream>
#include <regex>

int main() {
    std::ifstream fin;

    fin.open("input.txt");

    std::string line;

    const std::regex numbers_regex("[0-9]");
    std::smatch first_number_match;

    while (getline(fin, line)) {
        if(std::regex_search(line, first_number_match, numbers_regex)) {
            std::cout << line << ": " << first_number_match.str() << '\n';
        }
    }

	return 0;
}