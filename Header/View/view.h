#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "boardmodel.h"
#include "playermodel.h"

using namespace std;

class View {
public:
	void Menu();
	void drawboard(board& boa);
	void endgame(Player pl);
};

#endif // !VIEW_H
