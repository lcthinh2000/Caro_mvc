#ifndef FUNCFILE_H
#define FUNCFILE_H

#include <iostream>
#include <fstream>
#include "playermodel.h"
#include "boardmodel.h"

using namespace std;

class FuncFile
{
public:
	FuncFile();
	
	void addPlayer(Player& pl);
	void History(Player& pl, int a, int b, int c);
	void infoHis(Player p1, Player p2, board boa);
	void result(string re);
	void resetfile();
	void resetlist();

private:

};

#endif // !FUNCFILE_H

