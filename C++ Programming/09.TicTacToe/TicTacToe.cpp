using namespace std;

class  TicTacToe {
	static const int SIZE = 3;
	char board[SIZE][SIZE];
	char mark;
public:
	TicTacToe(char startMark);
	~TicTacToe();
	initializeBoard();
	isThereWinner();
	markOnBoard();
	printBoard();
};

TicTacToe::TicTacToe(char startMark) {
	this->mark = startMark;
	
	initializeBoard();
	
	char winnerMark;
	while (true) {
		winnerMark = isThereWinner();
		if (winnerMark != 'N') {
			break;
		}
		
		markOnBoard();
		printBoard();
	}
	
	cout << endl << "The winner is the player who puts " << winnerMark << ". Congratulation! :)"  << endl << endl;
}

TicTacToe::~TicTacToe() {}

TicTacToe::initializeBoard() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			board[i][j] = ' ';
		}
	}
}

TicTacToe::isThereWinner() {
	for (int i = 0; i < SIZE; i++) {
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return board[i][0];
		}
		
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			return board[0][i];
		}
	}
	
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		return board[0][0];
	}
	
	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		return board[0][2];
	}
	
	return 'N';
}

TicTacToe::markOnBoard() {
	int position;
	int index;
	
	while (true) {
		cout << endl << "==================================================" << endl;
		string position_str;
		cout << "It's turn for mark " << mark << ". :)" << endl;
		cout << "Where do you want to mark ?? (Select a number from 1 - 9) : ";
		cin >> position_str;
		
		if (position_str.length() != 1) {
			cout << endl << "You should input only one number. :(" << endl;
			cout << "==================================================" << endl << endl;
			continue;
		}
		
		char position_char = position_str[0];
		position = position_char - '0';
		
		if (position < 1 || position > 9) {
			cout << endl << "You should input number between 1 and 9. :(" << endl;
			cout << "==================================================" << endl << endl;
			continue;
		}
		
		break;
	}
	
	index = position - 1;
	int row = index / 3;
	int col = index % 3;
	
	board[row][col] = mark;
	if (mark == 'O') {
		mark = 'X';
	} else {
		mark = 'O';
	}
}

TicTacToe::printBoard() {
	cout << endl;
	
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << board[i][j] << " | ";
		}
		
		cout << endl;
	}
	
	cout << "==================================================" << endl << endl;
}
