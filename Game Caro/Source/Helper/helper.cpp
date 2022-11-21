#include "helper.h"

Helper::Helper() {

}

bool Helper::checkcolumn(Player pl, board boa) {
	for (int i = 0; i < boa.get_w(); i++) {
		for (int j = 0; j < boa.get_h(); j++) {
			if (boa.get_arr(i, j) == pl.getKH() && boa.get_arr(i, j + 1) == pl.getKH()
				&& boa.get_arr(i, j + 2) == pl.getKH() && boa.get_arr(i, j + 3) == pl.getKH()) {
				  return true;
			}
		}
	}
}

bool Helper::checkrow(Player pl, board boa) {
	for (int i = 0; i < boa.get_w(); i++) {
		for (int j = 0; j < boa.get_h(); j++) {
			if (boa.get_arr(i, j) == pl.getKH() && boa.get_arr(i + 1, j) == pl.getKH()
				&& boa.get_arr(i + 2, j) == pl.getKH() && boa.get_arr(i + 3, j) == pl.getKH()) {
				return true;
			}
		}
	}
}

bool Helper::checkdiagonal1(Player pl, board boa) {
	for (int i = 0; i < boa.get_w(); i++) {
		for (int j = 0; j < boa.get_h(); j++) {
			if (boa.get_arr(i, j) == pl.getKH() && boa.get_arr(i + 1, j + 1) == pl.getKH()
				&& boa.get_arr(i + 2, j + 2) == pl.getKH() && boa.get_arr(i + 3, j + 3) == pl.getKH()) {
				return true;
			}
		}
	}
}

bool Helper::checkdiagonal2(Player pl, board boa) {
	for (int i = 0; i < boa.get_w(); i++) {
		for (int j = 0; j < boa.get_h(); j++) {
			if (boa.get_arr(i, j) == pl.getKH() && boa.get_arr(i + 1, j - 1) == pl.getKH()
				&& boa.get_arr(i + 2, j - 2) == pl.getKH() && boa.get_arr(i + 3, j - 3) == pl.getKH()) {
				return true;
			}
		}
	}
}