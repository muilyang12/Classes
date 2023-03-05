#include <iostream>
#include "Stack.cpp"

using namespace std;

int main()
{
	Stack<string>* strStack = new Stack<string>(5);

    strStack->push("A");
    strStack->push("B");
    strStack->push("C");
    strStack->push("D");
    strStack->push("E");
    
    while (!strStack->isEmpty()) {
        cout << strStack->pop() << endl;
	}

    delete strStack;
}