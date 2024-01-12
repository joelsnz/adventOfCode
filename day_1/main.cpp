#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin;

    fin.open("input.txt");

    std::string line;

    int *pNumbers = NULL;
    int size;
    int line_number = 0;
    int result = 0;

    while (getline(fin, line)) {
        int number;
        size = 0;

        // determine the size of the array of numbers
        for (int i = 0; i < line.length(); i++) {
            number = (int)(line[i] - '0');
            if (number <= 9) {
                size++;
            }
        }

        // assing size to the array
        pNumbers = new int[size];
        int index = 0;

        // fill the array of numbers
        for (int i = 0; i < line.length(); i++) {
            number = (int)(line[i] - '0');
            if (number <= 9) {
                pNumbers[index] = number;
                index++;
            }
        }

        // create the number with the first and last element of the line
        if (size != 1) {
          line_number = (pNumbers[0] * 10) + pNumbers[index - 1];
        } else {
          line_number = (pNumbers[0] * 10) + pNumbers[0];
        }
        // add line number to the total
        result += line_number;

        // delete the pointer
        delete[] pNumbers;
    }
    // display the result
    std::cout << "Result: " << result << '\n';
	return 0;
}
