#include "Produce.h"

Produce::Produce()
{
	srand(time(0));
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			board[i][j] = 0;
		}
	}
	int place1 = (rand() % 16);
	int place2 = place1;
	while (place1 == place2) place2 = (rand() % 16);
	int count = 0;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (count == place1 || count == place2) {
				board[i][j] = 2;
			}
			count++;
		}
	}
}


void Produce::generate_random_tile()
{
	srand(time(0));
	int amount = (rand() % 2 + 1);
	int empty = 0;
	int place[2];

	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (board[i][j] == 0) empty++;
		}
	}
	if (empty == 1)
		amount = 1;

	if (amount == 1) {
		place[0] = -1;
		place[1] = 0;
		for (int i = 0;i < 1;i++) {
			for (int j = 0;j < 1;j++) {
				if (board[i][j] == 0) place[1] = 4 * i + j;
			}
		}
	}
	else {
		place[0] = (rand() % empty);
		place[1] = place[0];
		while (place[0] == place[1]) place[1] = (rand() % empty);
	}
	int count = 0;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (board[i][j] == 0) {
				if (count == place[0] || count == place[1]) {
					board[i][j] = ((rand() % 2 + 1)) * 2;
					count++;
				}
				else count++;
			}
		}
	}
}

void Produce::print_board()
{

	cout << "\n2048\n";
	cout << "-----------------------------\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "| " << setw(4) << board[i][j] << " ";
		}
		cout << "|\n";
		cout << "-----------------------------\n";
	}
}
