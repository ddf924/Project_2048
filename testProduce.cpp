#include"Produce.h"

//test
int main() {
	Produce a;
	a.print_board();
	cout << endl;
	for (int i = 0;i < 5;i++) {
		a.generate_random_tile();
		a.print_board();
		cout << endl;
	}
}

