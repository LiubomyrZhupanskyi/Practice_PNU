#include <iostream>
#include <vector>

// A function for calculating the Nth row of Pascal's triangle
std::vector<int> generatePascalRow(int rowNumber) {
    std::vector<int> row;

    // The first element is always 1
    row.push_back(1);

    // We generate a line using the previous line
    for (int i = 1; i <= rowNumber; ++i) {
        // Додаємо число в рядок
        row.push_back(row[i - 1] * (rowNumber - i + 1) / i);
    }

    return row;
}

int main() {
    int rowNumber;
    std::cout << "Enter the row number of Pascal's triangle: ";
    std::cin >> rowNumber;

    // Checking the correctness of the entered line number
    if (rowNumber < 0) {
        std::cerr << "The line number must be at least 0." << std::endl;
        return 1;
    }

    // We generate and output the Nth row of Pascal's triangle
    std::vector<int> row = generatePascalRow(rowNumber);
    std::cout << "The Nth row of Pascal's triangle: ";
    for (int num : row) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

}