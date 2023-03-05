#include <iostream>
#include "Circle.h"

using namespace std;

Circle::Circle(const std::string n, const int fs) {
    name = n;
    figureSn = fs;
}

Circle::~Circle() {}

void Circle::setCenter(double x, double y) {
    cx = x;
    cy = y;
}

void Circle::setRadius(double r) {
    radius = r;
}

void Circle::move(double dx, double dy) {
    cx += dx;
    cy += dy;
}

void Circle::scale(double s) {
    cx *= s;
    cy *= s;
    radius *= s;
}

void Circle::print() {
    cout << "Figure Sn: " << figureSn << ", Name: " << name << endl;
    cout << "Center: (" << cx << ", " << cy << ")" << endl;
    cout << "Radius: " << radius << endl;
}