#include "Counter.h"

Counter::Counter(int n) : number(n) {}

Counter::~Counter() {}

// Prefix increment operator
Counter& Counter::operator++ () {
    ++number;
    return *this;
}

// Postfix increment operator
Counter Counter::operator++ (int) {
    Counter tempCounter(*this);
    ++number;
    return tempCounter;
}

Counter& Counter::operator+= (const Counter& c) {
    number += c.number;
    return *this;
}

Counter& Counter::operator+= (int n) {
    number += n;
    return *this;
}

Counter Counter::operator+ (const Counter& c) const {
    return Counter(number + c.number);
}

Counter Counter::operator+ (int n) const {
    return Counter(number + n);
}

Counter::operator int() const {
    return number;
}

int Counter::getCounterNum() const {
    return number;
}