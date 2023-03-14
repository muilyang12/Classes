#include <iostream>
#include "02.Heap.h"

#define MAX_SIZE 100

int Heap::getParentIndex(int index) {
    return index / 2;
}

int Heap::getLeftChildIndex(int index) {
    return index * 2;
}

int Heap::getRightChildIndex() {
    return index * 2 + 1;
}

Heap::Heap() {
    size = 0;
    heapArray = new int[MAX_SIZE];
}

Heap::~Heap() {
    size = NULL;
    
    delete heapArray;
    heapArray = NULL;
}

int Heap::isEmpty() {
    if (size == 0) {
        return true;
    } else {
        return false;
    }
}

void Heap::push(int data) {
    
}

int Heap::pop() {
    
}

void Heap::top() {
    
}