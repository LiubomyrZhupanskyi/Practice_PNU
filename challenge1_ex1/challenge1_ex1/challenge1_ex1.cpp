#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


int main() {
    setlocale(LC_CTYPE, "ukr");
    // The path to the input file
    std::string inputFilePath = "input.txt";
    // The path to the source file
    std::string outputFilePath = "output.txt";

    std::ifstream inputFile(inputFilePath, std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to own input file." << std::endl;
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(inputFile)),
        (std::istreambuf_iterator<char>()));

    std::reverse(content.begin(), content.end());

    std::ofstream outputFile(outputFilePath, std::ios::binary);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open source file." << std::endl;
        return 1;
    }

    outputFile << content;

    std::cout << "File successfully canceled and saved to " << outputFilePath << std::endl;

    return 0;
}
