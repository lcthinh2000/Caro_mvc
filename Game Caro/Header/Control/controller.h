#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "client.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include "boardmodel.h"
#include "playermodel.h"
#include "view.h"
#include "helper.h"
#include "funcfile.h"
#include "listaccount.h"

class Control {
public:
	Control();
	bool checkwin(Player pl, board boa, Helper help);
	void run(View view, board boa, Player p1, Player p2, Helper help, FuncFile ff, Client cli);
	void playGame(Player p1, Player p2, int w, int h, int count, board boa, FuncFile ff, View view, Helper help, Client cli);
	void listpl(View view, board boa, Player p1, Player p2, Helper help, FuncFile ff, Client cli);
	void replay(int a, int c, View view, board boa, Player p1, Player p2, Helper help, FuncFile ff, Client cli);
	void playOnl(string acc, View view, board boa, Player p1, Player p2, Helper help, FuncFile ff, Client cli, AccountList acclist);
	void account(View view, board boa, Player p1, Player p2, Helper help, FuncFile ff, Client cli, AccountList acclist);
	void inAcc(string acc, View view, board boa, Player p1, Player p2, Helper help, FuncFile ff, Client cli, AccountList acclist);
};

#endif // !CONTROLLER_H
