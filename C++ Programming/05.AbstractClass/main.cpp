#include <iostream>
#include "Circle.h"
#include "Triangle.h"

int main() {
    auto pCircle = std::make_shared<Circle>("Circle 01", 1);
    pCircle->setCenter(0, 0);
    pCircle->setRadius(1);

    pCircle->print();
    pCircle->move(2, 2);
    pCircle->print();

    std::cout << "\n\n";

    auto pTriangle = std::make_shared<Triangle>("Triangle 01", 2);
    double data[3][2] = { {0.0, 0.0}, {1.0, 1.0}, {1.0, 0.0} };
    pTriangle->setPoints(data);

    pTriangle->print();
    pTriangle->scale(2);
    pTriangle->print();
}