#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

//Function for combining and sorting arrays
std::vector<int> mergeAndSortArrays(const std::vector<std::vector<int>>& arrays) {
    // We create a set to store unique elements
    std::set<int> uniqueElements;

    // We iterate over each array and add its elements to the set
    for (const auto& array : arrays) {
        for (int num : array) {
            // We add only unique elements that are not multiples of 5
            if (num % 5 != 0) {
                uniqueElements.insert(num);
            }
        }
    }

    // Let's convert the set to a vector, because we want to preserve the order
    std::vector<int> result(uniqueElements.begin(), uniqueElements.end());

    // Sort the result in ascending order
    std::sort(result.begin(), result.end());

    return result;
}

int main() {
    // Example of input arrays
    std::vector<std::vector<int>> arrays = {
        {3, 5, 7, 10, 12},
        {2, 5, 8, 11},
        {1, 4, 6, 9, 13, 15}
    };

    // Combine and sort arrays
    std::vector<int> mergedArray = mergeAndSortArrays(arrays);

    // We derive the result
    std::cout << "The result of combining and sorting arrays:" << std::endl;
    for (int num : mergedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
