#include <iostream>
#include <map>

using namespace std;

int main() {
	map<string, string> phoneBook;
	phoneBook.insert({ "Yang", "0109187" });
	phoneBook.insert(make_pair("Kim", "0105026"));

	cout << "Before change -> Yang: " << phoneBook["Yang"] << endl;
	phoneBook.at("Yang") = "0105431";
	cout << "After change -> Yang: " << phoneBook["Yang"] << endl;

	cout << "\n==================================================\n" << endl;

	for (auto p = phoneBook.begin(); p != phoneBook.end(); p++) {
		cout << p->first << ": " << p->second << endl;
	}

	for (auto& p : phoneBook) {
		cout << p.first << ": " << p.second << endl;
	}

	cout << "Number of people enrolled: " << phoneBook.size() << endl;
}