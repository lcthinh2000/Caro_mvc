#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include "boardmodel.h"
#include "playermodel.h"

using namespace std;

class Helper {
public:
	Helper();

	bool checkcolumn(Player pl, board boa);
	bool checkrow(Player pl, board boa);
	bool checkdiagonal1(Player pl, board boa);
	bool checkdiagonal2(Player pl, board boa);
};

#endif // !HELPER_H

