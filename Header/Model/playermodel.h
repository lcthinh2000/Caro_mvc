#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include <iostream>
#include <string>
#include "boardmodel.h"

using namespace std;

class Player {
private:
	string name;
	char kh;
public:
	Player();
	Player(string name, char kh);

	void setName(string name);
	void setKH(char kh);

	string getName();
	char getKH();

	void turn(board& boa);
};

#endif // !PLAYERMODEL_H
