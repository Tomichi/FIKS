#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct ChessField {
	int value = 0;
	int position = 0;
} ChessField;

typedef struct Cord {
	int x = 0;
	int y = 0;
} Cord;

int compare(const void *a, const void *b) {

	ChessField *ChesseFieldA = (ChessField *) a;
	ChessField *ChesseFieldB = (ChessField *) b;

	return ChesseFieldB->value - ChesseFieldA->value;
}

bool isInputCorrect(const int n);

void printChessBoardArray(const ChessField *chessBoardArray, const int n);

void fillDiagonals(ChessField *chessBoardArray, const int n, const Cord cords, const int number);

int main(void) {
	int n;
	cin >> n;
	if (isInputCorrect(n)) {
		cout << "Spatny vstup bro \n";
		return 1;
	}

	ChessField *chessGameBoard = new ChessField[n * n];
	Cord chessField;
	int fieldValue;
	int position;
	// load it and fill diagonals
	for (int i = 0; i < n; i++) {
		chessField.y = i;
		for (int j = 0; j < n; j++) {
			chessField.x = j;
			cin >> fieldValue;
			position = (i * n) + j;
			chessGameBoard[position].position = position;
			fillDiagonals(chessGameBoard, n, chessField, fieldValue);
		}
	}

	qsort(chessGameBoard, n * n, sizeof(ChessField), compare);
	bool same = false, difrent = false;
	if (chessGameBoard[0].position % 2 == ((chessGameBoard[0].position / n) % 2)) {
		same = true;
	} else {
		difrent = true;
	}

	//printChessBoardArray(chessGameBoard, n);

	for (int i = 1; i < n; i++) {
		if ((same == false && chessGameBoard[i].position % 2 == (chessGameBoard[i].position / n) % 2) ||
			(difrent = false && chessGameBoard[i].position % 2 != (chessGameBoard[i].position / n) % 2 )) {
			cout << chessGameBoard[0].value + chessGameBoard[i].value
			<< " " << (chessGameBoard[0].position / n) + 1  << " " << (chessGameBoard[0].position % n) + 1  << " "
			<< (chessGameBoard[i].position / n) + 1 << " " << (chessGameBoard[i].position % n) + 1 << "\n";
			break;
		}
	}

	//printChessBoardArray(chessGameBoard, n);

	delete[] chessGameBoard;

	return 0;
}

bool isInputCorrect(const int n) {
	return !(n > 1 && n < 2001);
}

void printChessBoardArray(const ChessField *chessBoardArray, const int n) {
	int maxRange = n * n;
	for (int position = 0; position < maxRange; position++) {
		cout << chessBoardArray[position].value << " ";
		if (position % n == n - 1) {
			cout << "\n";
		}
	}
}

void fillDiagonals(ChessField *chessBoardArray, const int n, const Cord cords, const int number) {
	if (number == 0) return;
	int small = cords.x >= cords.y ? cords.y : cords.x;
	for (int x = cords.x - small, y = cords.y - small; x < n && y < n; x++, y++) {
		chessBoardArray[(y * n) + x].value += number;
	}

	for (int x = cords.x + 1, y = cords.y - 1; x < n && y > -1; x++, y--) {
		chessBoardArray[(y * n) + x].value += number;
	}

	for (int x = cords.x - 1, y = cords.y + 1; x > -1 && y < n; x--, y++) {
		chessBoardArray[(y * n) + x].value += number;
	}

}
