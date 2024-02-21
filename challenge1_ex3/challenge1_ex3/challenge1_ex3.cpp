#include <iostream>
#include <cmath>
#include <locale>

struct Point {
    double x;
    double y;
};

double calculateAngle(const Point& origin, const Point& point) {
    return atan2(point.y - origin.y, point.x - origin.x);
}

int main() {
    // We set the locale of the Ukrainian language
    std::locale::global(std::locale(""));

    Point origin{ 0.0, 0.0 };
    Point A, B;

    // We read the coordinates of the points
    std::cout << "Enter the coordinates of point A (x1, y1): ";
    std::cin >> A.x >> A.y;

    std::cout << "Enter the coordinates of point B (x2, y2): ";
    std::cin >> B.x >> B.y;

    // Calculation of the angles between segments and the Ox axis
    double angleAOx = std::abs(calculateAngle(origin, A));
    double angleBOx = std::abs(calculateAngle(origin, B));

    // Determining which segment forms a larger angle with Ox
    if (angleAOx > angleBOx) {
        std::cout << "The segment OA forms a larger angle with the Ox axis.\n";
    }
    else if (angleAOx < angleBOx) {
        std::cout << "The segment OB forms a larger angle with the axis Ox.\n";
    }
    else {
        std::cout << "Segments OA and OB form the same angle with the axis Ox.\n";
    }

    return 0;
}
