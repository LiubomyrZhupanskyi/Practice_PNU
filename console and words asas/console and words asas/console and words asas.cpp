#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <locale>

// A function to clear a word from punctuation marks and lowercase it
std::string clean_word(const std::string& word) {
    std::string cleaned_word;
    for (char c : word) {
        if (isalpha(c, std::locale("uk_UA.UTF-8"))) {
            cleaned_word += tolower(c, std::locale("uk_UA.UTF-8"));
        }
    }
    return cleaned_word;
}

int main() {
    std::string file_path;
    std::cout << "Enter the file path: ";
    std::cin >> file_path;

    std::ifstream file(file_path);
    if (!file) {
        std::cerr << "Error: Unable to open file\n";
        return 1;
    }

    std::unordered_map<std::string, int> word_frequency;

    std::string word;
    while (file >> word) {
        std::string cleaned_word = clean_word(word);
        if (!cleaned_word.empty()) {
            word_frequency[cleaned_word]++;
        }
    }

    // Creating a vector with pairs (word, frequency)
    std::vector<std::pair<std::string, int>> word_frequency_vector;
    for (const auto& pair : word_frequency) {
        word_frequency_vector.push_back(pair);
    }

    // Vector sorting by frequency
    std::sort(word_frequency_vector.begin(), word_frequency_vector.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second;
        });

    // Output of results
    std::cout << "Words and their frequency of use:\n";
    for (const auto& pair : word_frequency_vector) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }

    return 0;
}
