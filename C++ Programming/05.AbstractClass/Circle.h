#include <iostream>
#include "Figure.cpp"

class Circle : public Figure {
    double cx, cy, radius;

public:
    Circle(const std::string n, const int fs);
    ~Circle();

    void setCenter(double x, double y);
    void setRadius(double r);
    void move(double dx, double dy);
    void scale(double s);
    void print();
};