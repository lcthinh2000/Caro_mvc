#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include "client.h"
#include <iostream>
#include <string>
#include "boardmodel.h"

using namespace std;

class Player {
private:
	string name;
	char kh;
	int win, lose, draw;
public:
	Player();
	Player(string name, char kh);
	Player(string name, char kh, int w, int l, int d);

	void setName(string name);
	void setKH(char kh);
	void setWin(int w);
	void setLose(int l);
	void setDraw(int d);

	string getName();
	char getKH();
	int getWin();
	int getLose();
	int getDraw();

	void turn(board& boa, int& i, int& j);
	void turnOnl(board& boa, Client& cli);
	void turnRep(board& boa, Client& cli);
};

#endif // !PLAYERMODEL_H
