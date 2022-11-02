#include "boardmodel.h"

board::board() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			arr[i][j] = ' ';
		}
	}
}

board::board(int w, int h) {
	this->w = w;
	this->h = h;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			arr[i][j] = ' ';
		}
	}
}

void board::set_w(int a) {
	this->w = a;
}

void board::set_h(int b) {
	this->h = b;
}

void board::set_arr(int a, int b, char c) {
	this->arr[a][b] = c;
}

int board::get_w() {
	return w;
}

int board::get_h() {
	return h;
}

char board::get_arr(int a, int b) {
	return arr[a][b];
}