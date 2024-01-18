#include <iostream>
#include <fstream>

int getNumbersQuantity(std::string input);
void fillArray(std::string input, int *array);
int getPart1(std::istream &input);
int getPart2(std::istream &input);

int main() {
    std::ifstream fin;

    fin.open("input.txt");

    int result_part_1 = getPart1(fin);
    int result_part_2 = 0;

    fin.close();

    // display the results
    std::cout << "-------------\n" << "Part 1: " << result_part_1 << '\n';
    std::cout << "Part 2: " << result_part_2 << "\n-------------\n";
    return 0;
}

int getNumbersQuantity(std::string input) {
    /* get the quantity of numbers in the passed string */
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

int getPart1(std::istream &input) {
    std::string line;

    int *pNumbers = NULL;
    int size;
    int line_number = 0;
    int result = 0;
    int number;

    while (getline(input, line)) {
        size = getNumbersQuantity(line);

        // assign size to the array
        pNumbers = new int[size];

        fillArray(line, pNumbers);

        // append the first and last element of pNumbers
        line_number = (pNumbers[0] * 10) + pNumbers[size - 1];

        // add line number to the total
        result += line_number;

        // delete the pointer
        delete[] pNumbers;
    }

    return result;
}


int getPart2(std::istream &input) {
    std::string line;

    int result = 0;
    int line_number = 0;

    return result;
}
