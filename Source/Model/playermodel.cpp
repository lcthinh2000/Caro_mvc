#include "playermodel.h"

Player::Player() {

}

Player::Player(string name, char kh) {
	this->name = name;
	this->kh = kh;
}

void Player::setName(string name) {
	this->name = name;
}

void Player::setKH(char kh) {
	this->kh = kh;
}

string Player::getName() {
	return name;
}

char Player::getKH() {
	return kh;
}

void Player::turn(board& boa) {
	int i, j;
	cout << "Player " << name << " turn: ";
	cin >> i >> j;
	if (i<1 || i>(boa.get_w()) || j<1 || j>(boa.get_h())||boa.get_arr(i-1,j-1)!=' ') {
		cout << "Invalid\n";
		Player::turn(boa);
	}
	boa.set_arr(i - 1, j - 1, kh);
}