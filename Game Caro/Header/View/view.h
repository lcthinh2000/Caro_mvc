#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <fstream>
#include <string>
#include "boardmodel.h"
#include "playermodel.h"

using namespace std;

class View {
public:
	void Menu();
	void drawboard(board& boa);
	void endgame(Player pl);
	void listplay();
	void addplay(Player& pl);
	void repl(string pl, char kh, int a, int b, int t, board& boar);
	void InfoRepl(string p1, string p2, int w, int h);
	void viewAcc();
	void viewMenuAcc(string acc);
	void listAcc();
};

#endif // !VIEW_H
