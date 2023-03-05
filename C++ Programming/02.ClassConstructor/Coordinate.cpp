#include <iostream>
#include "Coordinate.h"

using namespace std;

Coordinate::Coordinate(double x, double y) : x{ x }, y{ y } {}

// Copy constructor
Coordinate::Coordinate(const Coordinate& coordinate) : x{ coordinate.x }, y{ coordinate.y } {}

// Move constructior
Coordinate::Coordinate(Coordinate&& coordinate) : x{ coordinate.x }, y{ coordinate.y } {
    coordinate.x = 0;
    coordinate.y = 0;
}

Coordinate::~Coordinate() {
    cout << "Coordinate deleted." << endl;
}

Coordinate Coordinate::moveToX(double dx) {
    Coordinate tempCoord(x, y);

    tempCoord.x += dx;

    return tempCoord;
}

Coordinate Coordinate::moveToY(double dy) {
    Coordinate tempCoord(x, y);

    tempCoord.y += dy;

    return tempCoord;
}

void Coordinate::print() {
    cout << "(" << x << ", " << y << ")" << endl;
}
