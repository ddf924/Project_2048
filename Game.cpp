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
				cout << "|          遊戲開始         |\n";
			else if (i == 4)
				cout << "|       （按空格繼續）      |\n";
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
				cout << "|         遊戲結束          |\n";
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
				A.board[i][k++] = A.board[i][j]; //非0方塊向左移
			}
		}
		while (k < 4) {
			A.board[i][k++] = 0;//剩餘方塊補0
		}
	}
}
void Game::mergeLeft() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (A.board[i][j] != 0 && A.board[i][j] == A.board[i][j + 1]) {
				A.board[i][j] *= 2;//方塊合併
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
				A.board[i][k--] = A.board[i][j]; //非0方塊向右移
			}
		}
		while (k >= 0) {
			A.board[i][k--] = 0;//剩餘方塊補0
		}
	}
}
void Game::mergeRight() {
	for (int i = 0;i < 4;i++) {
		for (int j = 3;j > 0;j--) {
			if (A.board[i][j] != 0 && A.board[i][j] == A.board[i][j - 1]) {
				A.board[i][j] *= 2;//方塊合併
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
				A.board[k++][j] = A.board[i][j]; //非0方塊向上移
			}
		}
		while (k < 4) {
			A.board[k++][j] = 0;//剩餘方塊補0
		}
	}
}
void Game::mergeUp() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (A.board[i][j] != 0 && A.board[i][j] == A.board[i + 1][j]) {
				A.board[i][j] *= 2;//方塊合併
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
				A.board[k--][j] = A.board[i][j]; //非0方塊向下移
			}
		}
		while (k >= 0) {
			A.board[k--][j] = 0;//剩餘方塊補0
		}
	}
}
void Game::mergeDown() {
	for (int j = 0; j < 4; j++) {
		for (int i = 3; i > 0; i--) {
			if (A.board[i][j] != 0 && A.board[i][j] == A.board[i - 1][j]) {
				A.board[i][j] *= 2; // 相同方塊合併
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
				return false; // 還有空格子，遊戲未結束
			}
			if (i > 0 && A.board[i][j] == A.board[i - 1][j]) {
				return false; // 還有相鄰且相同的方塊，遊戲未結束
			}
			if (j > 0 && A.board[i][j] == A.board[i][j - 1]) {
				return false; // 還有相鄰且相同的方塊，遊戲未結束
			}
		}
	}
	A.print_board();
	return true; // 沒有空格子且沒有相鄰且相同的方塊，遊戲結束
}