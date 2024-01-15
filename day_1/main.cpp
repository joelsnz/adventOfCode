#include <iostream>
#include <fstream>

int getNumbersQuantity(std::string input);
void fillArray(std::string input, int *array);

int main() {
    std::ifstream fin;

    fin.open("input.txt");

    std::string line;

    int *pNumbers = NULL;
    int size;
    int line_number = 0;
    int result = 0;
    int number;

    while (getline(fin, line)) {
        size = getNumbersQuantity(line);

        // assing size to the array
        pNumbers = new int[size];

        fillArray(line, pNumbers);

        // create the number with the first and last element of the line
        if (size != 1) {
          line_number = (pNumbers[0] * 10) + pNumbers[size - 1];
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

int getNumbersQuantity(std::string input) {
    /* determine the size of the array of numbers */
    int quantity = 0;
    for (int i = 0; i < input.length(); i++) {
        if ((int)(input[i] - '0') <= 9) {
            quantity++;
        }
    }
    return quantity;
}

void fillArray(std::string input, int *array) {
    /* fill the array of numbers */
    int position = 0;

    for (int i = 0; i < input.length(); i++) {
        if ((int)(input[i] - '0') <= 9) {
            array[position] = (int)input[i] - '0';
            position++;
        }
    }
    return;
}
