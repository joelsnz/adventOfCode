#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin;

    fin.open("input.txt");

    std::string line;

    int *pNumbers = NULL;
    int size;
    int line_number = 0;

    while (getline(fin, line)) {
        int number;
        for (int i = 0; i < line.length(); i++) {
            number = (int)(line[i] - '0');
            if (number <= 9) {
                size++;
            }
        }

        std::cout << "Size: " << size << '\n';
        
        pNumbers = new int[size];
        int index = 0;
        
        for (int i = 0; i < line.length(); i++) {
            number = (int)(line[i] - '0');
            if (number <= 9) {
                pNumbers[index] = number;
                index++;
            }
        }
/*
        for (int i = 0; i < size; i++) {
            std::cout << pNumbers[i];
        }
*/
        delete[] pNumbers;
        size = 0;
        std::cout << '\n';
    }

	return 0;
}