#include <iostream>
#include "Triangle.h"

using namespace std;

Triangle::Triangle(const std::string n, const int fs) {
    name = n;
    figureSn = fs;
}

Triangle::~Triangle() {}

void Triangle::setPoints(const double v[3][2]) {
    x1 = v[0][0]; y1 = v[0][1];
    x2 = v[1][0]; y2 = v[1][1];
    x3 = v[2][0]; y3 = v[2][1];
}

void Triangle::move(double dx, double dy) {
    x1 += dx; y1 += dy;
    x2 += dx; y2 += dy;
    x3 += dx; y3 += dy;
}

void Triangle::scale(double s) {
    x1 *= s; y1 *= s;
    x2 *= s; y2 *= s;
    x3 *= s; y3 *= s;
}

void Triangle::print() {
    cout << "Figure Sn: " << figureSn << ", Name: " << name << endl;
    cout << "Point 1: (" << x1 << ", " << y1 << ")" << endl;
    cout << "Point 2: (" << x2 << ", " << y2 << ")" << endl;
    cout << "Point 3: (" << x3 << ", " << y3 << ")" << endl;
}