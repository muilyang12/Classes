#include <iostream>
#include <queue>
#include "02.Heap.cpp"

using namespace std;

int main() {
    priority_queue<int>* pq01 = new priority_queue<int>();
    pq01.push(50);
    pq01.push(30);
    pq01.push(40);
    pq01.push(20);
    pq01.push(10);

    while (!pq.empty()) {
        cout << pq01.top() << " ";
        pq01.pop();
    }
    cout << endl;

    delete pq01;

    Heap* pq02 = new Heap();
    pq02.push(50);
    pq02.push(30);
    pq02.push(40);
    pq02.push(20);
    pq02.push(10);

    while (!pq.isEmpty()) {
        cout << pq02.top() << " ";
        pq02.pop();
    }
    cout << endl;

    delete pq02;
}