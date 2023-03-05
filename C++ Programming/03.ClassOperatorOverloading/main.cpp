#include <iostream>
#include "Counter.h"

using namespace std;

int main() {
    Counter counter1{ 10 };
    cout << (counter1++).getCounterNum() << endl; // 10
    cout << counter1.getCounterNum() << endl << endl; // 11

    Counter counter2{ 10 };
    cout << (++counter2).getCounterNum() << endl; // 11
    cout << counter2.getCounterNum() << endl << endl; // 11

    Counter counter3{ 10 };
    Counter counter4{ 10 };
    cout << counter3.getCounterNum() << endl; // 10
    counter3 += counter4;
    cout << counter3.getCounterNum() << endl; // 20
    counter3 += 5;
    cout << counter3.getCounterNum() << endl << endl; // 25

    Counter counter5 = counter3 + counter4;
    cout << counter5.getCounterNum() << endl; // 35
    Counter counter6 = counter5 + 10;
    cout << counter6.getCounterNum() << endl; // 45
}