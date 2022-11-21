#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include<iostream>

using namespace std;

class board {
private:
	int w, h;
	char arr[100][100];
public:
	board();
	board(int w, int h);

	void set_w(int a);
	void set_h(int b);
	void set_arr(int a, int b, char c);

	int get_w();
	int get_h();
	char get_arr(int a, int b);

};

#endif // !BOARDMODEL_H
