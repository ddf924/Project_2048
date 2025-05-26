#include "Game.h"
#include<iostream>
using namespace std;

Game::Game(Produce A) {
	this->A = A;
}
void Game::play() {
	char ch;
	for (;;) {
		cout << "-----------------------------\n";

		for (int i = 0;i < 7;i++) {
			if (i == 3)
				cout << "|          �C���}�l         |\n";
			else if (i == 4)
				cout << "|       �]���Ů��~��^      |\n";
			else
				cout << "|                           |\n";
		}
		cout << "-----------------------------\n";
		ch = getchar();
		if (ch == ' ')
			break;
	}


	while (!isGameOver()) {

		A.print_board();

		char move;
		cin >> move;
		switch (move)
		{
		case 'w':
			moveUp();
			break;
		case 'a':
			moveLeft();
			break;
		case 's':
			moveDown();
			break;
		case 'd':
			moveRight();
			break;
		}
		A.generate_random_tile();
	}
	if (isGameOver() == true) {
		cout << "-----------------------------\n";

		for (int i = 0;i < 7;i++) {
			if (i == 3)
				cout << "|         �C������          |\n";
			else
				cout << "|                           |\n";
		}
		cout << "-----------------------------\n";
	}


}

void Game::shiftLeft() {
	for (int i = 0;i < 4;i++) {
		int k = 0;
		for (int j = 0;j < 4;j++) {
			if (A.board[i][j] != 0) {
				A.board[i][k++] = A.board[i][j]; //�D0����V����
			}
		}
		while (k < 4) {
			A.board[i][k++] = 0;//�Ѿl�����0
		}
	}
}
void Game::mergeLeft() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (A.board[i][j] != 0 && A.board[i][j] == A.board[i][j + 1]) {
				A.board[i][j] *= 2;//����X��
				A.board[i][j + 1] = 0;
			}
		}
	}
}
void Game::moveLeft() {
	shiftLeft();
	mergeLeft();
	shiftLeft();
}
void Game::shiftRight() {
	for (int i = 0;i < 4;i++) {
		int k = 3;
		for (int j = 3; j >= 0; j--) {
			if (A.board[i][j] != 0) {
				A.board[i][k--] = A.board[i][j]; //�D0����V�k��
			}
		}
		while (k >= 0) {
			A.board[i][k--] = 0;//�Ѿl�����0
		}
	}
}
void Game::mergeRight() {
	for (int i = 0;i < 4;i++) {
		for (int j = 3;j > 0;j--) {
			if (A.board[i][j] != 0 && A.board[i][j] == A.board[i][j - 1]) {
				A.board[i][j] *= 2;//����X��
				A.board[i][j - 1] = 0;
			}
		}
	}
}
void Game::moveRight() {
	shiftRight();
	mergeRight();
	shiftRight();
}
void Game::shiftUp() {
	for (int j = 0;j < 4;j++) {
		int k = 0;
		for (int i = 0;i < 4;i++) {
			if (A.board[i][j] != 0) {
				A.board[k++][j] = A.board[i][j]; //�D0����V�W��
			}
		}
		while (k < 4) {
			A.board[k++][j] = 0;//�Ѿl�����0
		}
	}
}
void Game::mergeUp() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (A.board[i][j] != 0 && A.board[i][j] == A.board[i + 1][j]) {
				A.board[i][j] *= 2;//����X��
				A.board[i + 1][j] = 0;
			}
		}
	}
}
void Game::moveUp() {
	shiftUp();
	mergeUp();
	shiftUp();
}
void Game::shiftDown() {
	for (int j = 0;j < 4;j++) {
		int k = 3;
		for (int i = 3;i >= 0;i--) {
			if (A.board[i][j] != 0) {
				A.board[k--][j] = A.board[i][j]; //�D0����V�U��
			}
		}
		while (k >= 0) {
			A.board[k--][j] = 0;//�Ѿl�����0
		}
	}
}
void Game::mergeDown() {
	for (int j = 0; j < 4; j++) {
		for (int i = 3; i > 0; i--) {
			if (A.board[i][j] != 0 && A.board[i][j] == A.board[i - 1][j]) {
				A.board[i][j] *= 2; // �ۦP����X��
				A.board[i - 1][j] = 0;
			}
		}
	}
}
void Game::moveDown() {
	shiftDown();
	mergeDown();
	shiftDown();
}
bool Game::isGameOver() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (A.board[i][j] == 0) {
				return false; // �٦��Ů�l�A�C��������
			}
			if (i > 0 && A.board[i][j] == A.board[i - 1][j]) {
				return false; // �٦��۾F�B�ۦP������A�C��������
			}
			if (j > 0 && A.board[i][j] == A.board[i][j - 1]) {
				return false; // �٦��۾F�B�ۦP������A�C��������
			}
		}
	}
	A.print_board();
	return true; // �S���Ů�l�B�S���۾F�B�ۦP������A�C������
}