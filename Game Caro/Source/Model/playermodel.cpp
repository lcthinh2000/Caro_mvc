#include "playermodel.h"

Player::Player() {
	
}

Player::Player(string name, char kh) {
	this->name = name;
	this->kh = kh;
}

Player::Player(string name, char kh, int w, int l, int d) {
	this->name = name;
	this->kh = kh;
	this->win = w;
	this->lose = l;
	this->draw = d;
}

void Player::setName(string name) {
	this->name = name;
}

void Player::setKH(char kh) {
	this->kh = kh;
}

void Player::setWin(int w) {
	this->win = w;
}

void Player::setLose(int l) {
	this->lose = l;
}

void Player::setDraw(int d) {
	this->draw = d;
}

string Player::getName() {
	return name;
}

char Player::getKH() {
	return kh;
}

int Player::getWin() {
	return win;
}

int Player::getLose() {
	return lose;
}

int Player::getDraw() {
	return draw;
}

void Player::turn(board& boa, int& i, int& j) {
	cout << "Player " << name << " turn: ";
	cin >> i >> j;
	if (i<1 || i>(boa.get_w()) || j<1 || j>(boa.get_h())||boa.get_arr(i-1,j-1)!=' ') {
		cout << "Invalid\n";
		Player::turn(boa, i, j);
	}
	boa.set_arr(i - 1, j - 1, kh);
}

void Player::turnOnl(board& boa, Client& cli) {
	int tdx, tdy;
	string mes;
	
	cout << "Turn " << getName() << ": ";
	cin >> tdx;
	mes = to_string(tdx);
	cli.sendMsg(mes);
	cin >> tdy;
	mes = to_string(tdy);
	cli.sendMsg(mes);
	boa.set_arr(tdx - 1, tdy - 1, getKH());
	
}

void Player::turnRep(board& boa, Client& cli) {
	int tdx, tdy;
	string rep;
	
	cout << "Waiting for " << getName();
	cli.listenReponse(rep);
	tdx = atoi(rep.c_str());
	cli.listenReponse(rep);
	tdy = atoi(rep.c_str());
	boa.set_arr(tdx - 1, tdy - 1, getKH());
	
}