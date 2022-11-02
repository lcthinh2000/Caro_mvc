#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include "boardmodel.h"
#include "playermodel.h"
#include "view.h"

class Control {
public:
	Control();
	bool checkwin(Player pl, board boa);
	void run(View view, board boa, Player p1, Player p2);
};

#endif // !CONTROLLER_H
