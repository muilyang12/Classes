#include <iostream>
#include "Coordinate.h"

int main()
{
    Coordinate* coord1 = new Coordinate(10, 10);
    Coordinate* coord2 = new Coordinate(*coord1);
    Coordinate* coord3 = new Coordinate(coord1->moveToX(5));

    coord1->print();
    coord2->print();
    coord3->print();

    std::cout << "Hello !!" << std::endl;

    delete coord1;
    delete coord2;
    delete coord3;
}