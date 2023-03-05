#pragma once

#include <iostream>

// Abstract class
class Figure {
protected:
    std::string name;
    int figureSn;

public:
    virtual ~Figure() {}

    // Pure virtual function -> Required to implement in the inheriting class.
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double s) = 0;
    virtual void print() = 0;
};