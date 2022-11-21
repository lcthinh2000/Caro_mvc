#include "view.h"

void View::Menu() {
	cout << "\t\tGame Caro\n";
	cout << "1. New game\n";
	cout << "2. Account\n";
	cout << "3. List player\n";
	cout << "4. Exit\n";
	cout << "\n Command: ";
}

void View::drawboard(board& boa) {
	for (int i = 0; i < boa.get_w(); i++) {
		for (int j = 0; j < boa.get_h(); j++) {
			cout << boa.get_arr(i, j);
			cout << "|";
		}
		cout << endl;
		for (int i = 0; i < boa.get_h(); i++) {
			cout << "--";
		}
		cout << endl;
	}
}

void View::endgame(Player pl) {
	cout << "Player: " << pl.getName() << " is winner!\n";
	cout << "\n1. Replay\n";
	cout << "2. Exit\n";
	cout << "Command: ";
}

void View::listplay() {
	ifstream ifs("listplayer.ini");
	if (!ifs) {
		cerr << "Error: file not opened." << endl;
		return;
	}
	string data;
}

void View::addplay(Player& pl) {
	string abc;
	int a, b, c;
	cout << "Name new player: "; cin >> abc;
	pl.setName(abc);
	cout << "Win: "; cin >> a;
	pl.setWin(a);
	cout << "Lose: "; cin >> b;
	pl.setLose(b);
	cout << "Draw: "; cin >> c;
	pl.setDraw(c);
}

void View::InfoRepl(string p1, string p2, int w, int h) {
	cout << "\tReplay Match\n";
	cout << "Player 1: " << p1 << " VS Player 2: " << p2 << endl;
	cout << "Board size: Width: " << w << "; Height: " << h << endl;
}

void View::repl(string pl, char kh, int a, int b, int t, board& boar) {
	cout << "\nTurn " << t << ": " << pl << " (" << kh << ") : " << a << " " << b << endl;
	boar.set_arr(a - 1, b - 1, kh);
	drawboard(boar);
}

void View::viewAcc() {
	cout << "\t\tACCOUNT\n";
	cout << "1. Login\n";
	cout << "2. Register Account\n";
	cout << "3. List Account\n";
	cout << "4. Exit\n";
}

void View::viewMenuAcc(string acc) {
	cout << "\t\tMenu Account\n";
	cout << "\nHello " << acc << "!\n";
	cout << "\n1. New game\n";
	cout << "2. Info account\n";
	cout << "3. Logout\n";
}

void View::listAcc() {
	string data;
	ifstream ifs("database/AccountList.ini");
	if (!ifs.is_open()) {
		cerr << "Error: file not opened." << endl;
		return;
	}
	cout << "\t\tList Account\n\n";
	ifs >> data; 
	cout << data << endl;
	while (!ifs.eof()) {
		ifs >> data;
		cout << data << endl;
	}
}