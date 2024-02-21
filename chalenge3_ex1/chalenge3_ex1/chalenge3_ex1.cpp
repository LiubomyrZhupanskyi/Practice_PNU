#include <iostream>
#include <vector>

// Creating a structure for storing point coordinates
struct Point {
    int x;
    int y;
};

// Function for finding the exit point
Point findExitPoint(const std::vector<std::vector<char>>& matrix, const Point& entryPoint) {
    Point exitPoint = entryPoint; // Починаємо з точки входу

    // For each symbol on the field, we check its influence on the direction of the ball
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            char symbol = matrix[i][j];
            if (symbol == '\\') { // We change the direction of the ball by 90 degrees to the right
                if (exitPoint.x == i) {
                    ++exitPoint.y;
                }
                else if (exitPoint.y == j) {
                    ++exitPoint.x;
                }
            }
            else if (symbol == '/') { // We change the direction of the ball by 90 degrees to the left
                if (exitPoint.x == i) {
                    --exitPoint.y;
                }
                else if (exitPoint.y == j) {
                    --exitPoint.x;
                }
            }
            else if (symbol == '_') { // We change the direction of the bullet to the opposite when it is hit vertically
                if (exitPoint.x == i) {
                    exitPoint.x = 2 * i - exitPoint.x;
                }
            }
            else if (symbol == '|') { // we change the direction of the ball to the opposite one when hit horizontally
                if (exitPoint.y == j) {
                    exitPoint.y = 2 * j - exitPoint.y;
                }
            }
        }
    }

    return exitPoint;
}

int main() {
    int N; // The size of the matrix-field
    std::cin >> N;

    Point entryPoint; // Entry point
    std::cin >> entryPoint.x >> entryPoint.y;

    // Creating a matrix-field
    std::vector<std::vector<char>> matrix(N, std::vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Finding the exit point
    Point exitPoint = findExitPoint(matrix, entryPoint);

    // Виведення координат точки виходу
    std::cout << "Exit point coordinates: " << exitPoint.x << " " << exitPoint.y << std::endl;

    return 0;
}
