#include <iostream>
#include "Figure.cpp"

class Triangle : public Figure {
    double x1, y1, x2, y2, x3, y3;

public:
    Triangle(const std::string n, const int fs);
    ~Triangle();

    void setPoints(const double v[3][2]);
    void move(double dx, double dy);
    void scale(double s);
    void print();
};