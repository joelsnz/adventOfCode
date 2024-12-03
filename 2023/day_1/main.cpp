#include <iostream>
#include <fstream>

int getNumbersQuantity(std::string input);
void fillArray(std::string input, int *array);
int *getPart1Numbers(std::istream &input);
int getPart2(std::istream &input);

int main() {
    std::ifstream fin;

    fin.open("input.txt");


    int *part_1_numbers = getPart1Numbers(fin);

    int result_part_1 = 0;

    for (int i = 0; i < (sizeof(part_1_numbers) / sizeof(int)); i++) {
        result_part_1 += part_1_numbers[i];
    }

    fin.close();

    // display the results
    std::cout  << "Part 1: " << result_part_1 << '\n';
    return 0;
}

int *getPart1Numbers(std::istream &input) {
    std::string line;

    int *pNumbers = NULL;
    int pNumbers_size;

    int line_number = 0;

    int *results = (int*)malloc(sizeof(int) * 999);
    int results_index;

    while (getline(input, line)) {
        // get quantity of numbers in current line
        pNumbers_size = getNumbersQuantity(line);

        // assign size to the array
        pNumbers = new int[pNumbers_size];

        // search for numbers and add them to the array
        fillArray(line, pNumbers);

        // append the first and last element of pNumbers
        line_number = (pNumbers[0] * 10) + pNumbers[pNumbers_size - 1];

        // add line number to the array
        results[results_index++] = line_number;

        // delete the pointer
        delete[] pNumbers;
    }

    return results;
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
