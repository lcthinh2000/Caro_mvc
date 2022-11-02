#include "view.h"

void View::Menu() {
	cout << "\t\tGame Caro\n";
	cout << "1. New game\n";
	cout << "2. Exit\n";
	cout << "\nCommand: ";
}

void View::drawboard(board& boa) {
	for (int i = 0; i < boa.get_w(); i++) {
		for (int j = 0; j < boa.get_h(); j++) {
			cout << boa.get_arr(i, j);
			cout << "|";
		}
		cout << "\n--------------------\n";
	}
}

void View::endgame(Player pl) {
	cout << "Player: " << pl.getName() << " is winner!";
}