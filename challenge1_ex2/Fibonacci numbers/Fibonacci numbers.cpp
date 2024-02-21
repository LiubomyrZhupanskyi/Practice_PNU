#include <iostream>
#include <locale> 

// A function to calculate Fibonacci numbers
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8"); // Locale settings

    int index;

    // User request for input of Fibonacci number index
    std::cout << "Enter the index of the Fibonacci number: ";
    std::cin >> index;

    // Derivation of the Fibonacci number by the specified index
    std::cout << "Fibonacci number with index " << index << " - " << fibonacci(index) << std::endl;

    return 0;
}
