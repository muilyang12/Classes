#include <iostream>
#include "TicTacToe.cpp"

using namespace std;

int main() {
	cout << "Welcome to TicTacToe game. :)" << endl << endl;
	
	char startMark;
	while (true) {
		string start_str;
		cout << "What do you want to use for the first mark ?? (O / X): ";
		cin >> start_str;
		
		if (start_str.length() != 1) {
			cout << endl << "You should input only one character. :("  << endl << endl;
			continue;
		}
		
		startMark = start_str[0];
		if (startMark != 'O' && startMark != 'X') {
			cout << endl << "You should choose a character between O and X. :("  << endl << endl;
			continue;
		}
		
		break;
	}
	
	TicTacToe ticTacToe(startMark);
	
	return 0;
}