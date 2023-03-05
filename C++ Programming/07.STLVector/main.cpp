#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int& a, const int& b);

// sequence container - vector
int main() {
    vector<int> intVector01 = { 3, 2, 1 };
    intVector01.at(1) = 20;

    cout << "intVector[0]: " << intVector01[0] << endl;
    cout << "intVector.at(1): " << intVector01.at(1) << endl;

    cout << "Size: " << intVector01.size() << endl;
    intVector01.push_back(4);
    cout << "Size: " << intVector01.size() << endl;
    intVector01.pop_back();
    cout << "Size: " << intVector01.size() << endl;

    cout << "\n==================================================\n" << endl;

    cout << "Data printing 01: ";
    for (int i = 0; i < intVector01.size(); i++) {
        cout << intVector01[i] << " ";
    }
    cout << endl;

    vector<int>::iterator itr = intVector01.begin();

    cout << "Data printing 02: ";
    for (; itr < intVector01.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    cout << "\n==================================================\n" << endl;

    vector<int> intVector02(5);
    for (auto& i : intVector02) {
        i = rand() % 100;
    }

    cout << "Before sorting: ";
    for (auto i : intVector02) {
        cout << i << " ";
    }
    cout << endl;

    sort(intVector02.begin(), intVector02.end());

    cout << "After sorting: ";
    for (auto i : intVector02) {
        cout << i << " ";
    }
    cout << endl;

    cout << "\n==================================================\n" << endl;

    vector<int> intVector03(2 * intVector02.size());

    cout << "Before merging: ";
    for (auto i : intVector03) {
        cout << i << " ";
    }
    cout << endl;

    merge(intVector02.begin(), intVector02.end(), intVector02.begin(), intVector02.end(), intVector03.begin());

    cout << "Before merging: ";
    for (auto i : intVector03) {
        cout << i << " ";
    }
    cout << endl;

    cout << "\n==================================================\n" << endl;

    cout << "Before sorting: ";
    for (auto i : intVector03) {
        cout << i << " ";
    }
    cout << endl;

    sort(intVector03.begin(), intVector03.end(), compare);

    cout << "Before sorting: ";
    for (auto i : intVector03) {
        cout << i << " ";
    }
    cout << endl;
}

bool compare(const int& a, const int& b) {
    return a > b;
}