#include "funcfile.h"

FuncFile::FuncFile() {

}

void FuncFile::addPlayer(Player& pl) {
	ofstream ofs("listplayer.ini", ios::app);
	if (!ofs) {
		cerr << "Error: file not opened." << endl;
		return ;
	}
	ofs << pl.getName() << " " << pl.getWin() << " " << pl.getLose() << " " << pl.getDraw() << endl;
	ofs.close();
}

void FuncFile::History(Player& pl, int a, int b, int c) {
	ofstream ofs("history.ini", ios::app);
	if (!ofs) {
		cerr << "Error: file not opened." << endl;
		return;
	}
	ofs << "Turn " << a + 1 << " : " << pl.getName() << " ( " << pl.getKH() << " ) " << " ";
	ofs << b << " " << c << endl;
	ofs.close();
}

void FuncFile::infoHis(Player p1, Player p2, board boa) {
	ofstream ofs("history.ini", ios::app);
	if (!ofs) {
		cerr << "Error: file not opened." << endl;
		return;
	}
	ofs << "Player 1: " << p1.getName() << endl << "Player 2: " << p2.getName() << endl;
	ofs << "Board: Width: " << boa.get_w() << " ;Height: " << boa.get_h() << endl;
	ofs.close();
}

void FuncFile::result(string re) {
	ofstream ofs("history.ini", ios::app);
	if (!ofs) {
		cerr << "Error: file not opened." << endl;
		return;
	}
	ofs << re << endl;
	ofs.close();
}

void FuncFile::resetfile() {
	ofstream ofs("history.ini", ios::out);
	if (!ofs) {
		cerr << "Error: file not opened." << endl;
		return;
	}
	ofs.close();
}

void FuncFile::resetlist() {
	ofstream ofs("listplayer.ini", ios::out);
	if (!ofs) {
		cerr << "Error: file not opened." << endl;
		return;
	}
	ofs.close();
}