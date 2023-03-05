#include <iostream>
#include "Stack.h"

using namespace std;

template <typename T>
Stack<T>::Stack(int s) : size(s), top(0) {
    buf = new T[s];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] buf;
}

template <typename T> 
bool Stack<T>::isFull() const {
    return top == size;
}

template <typename T> 
bool Stack<T>::isEmpty() const {
    return top == 0;
}

template <typename T> 
void Stack<T>::push(const T& a) {
    buf[top++] = a;
}

template <typename T> 
void Stack<T>::push(T&& a) {
    buf[top++] = move(a);
}

template <typename T> 
T&& Stack<T>::pop() {
    return move(buf[--top]);
}