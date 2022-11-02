#include "controller.h"

Control::Control()
{
}

bool Control::checkwin(Player pl, board boa) {
    for (int i = 0; i < boa.get_w(); i++) {
        for (int j = 0; j < boa.get_h(); j++) {
            if ((boa.get_arr(i, j) == pl.getKH() && boa.get_arr(i, j + 1) == pl.getKH()
                && boa.get_arr(i, j + 2) == pl.getKH() && boa.get_arr(i, j + 3) == pl.getKH()) ||
                (boa.get_arr(i, j) == pl.getKH() && boa.get_arr(i + 1, j) == pl.getKH()
                    && boa.get_arr(i + 2, j) == pl.getKH() && boa.get_arr(i + 3, j) == pl.getKH()) ||
                (boa.get_arr(i, j) == pl.getKH() && boa.get_arr(i + 1, j + 1) == pl.getKH()
                    && boa.get_arr(i + 2, j + 2) == pl.getKH() && boa.get_arr(i + 3, j + 3) == pl.getKH()) ||
                (boa.get_arr(i, j) == pl.getKH() && boa.get_arr(i + 1, j - 1) == pl.getKH()
                    && boa.get_arr(i + 2, j - 2) == pl.getKH() && boa.get_arr(i + 3, j - 3) == pl.getKH())) {
                return true;
            }
        }
    }
}

void Control::run(View view, board boa, Player p1, Player p2) {
    int command;
    int w, h;
    string n1, n2;
    p1.setKH('X');
    p2.setKH('O');
    view.Menu();
    cin >> command;
    switch (command)
    {
    case 1:
        cout << "Name player 1: ";
        cin >> n1;
        p1.setName(n1);
        cout << "Name player 2: ";
        cin >> n2;
        p2.setName(n2);
        cout << "Board size: \n";
        cout << "Width: "; cin >> w;
        cout << "Height: "; cin >> h;
        boa.set_w(w); boa.set_h(h);
        system("cls");
        view.drawboard(boa);
    turn1:
        p1.turn(boa);
        system("cls");
        view.drawboard(boa);
        if (checkwin(p1, boa) == true) {
            view.endgame(p1);
            break;
        }
        else {
            goto turn2;
        }
    turn2:
        p2.turn(boa);
        system("cls");
        view.drawboard(boa);
        if (checkwin(p2, boa) == true) {
            view.endgame(p2);
            break;
        }
        else {
            goto turn1;
        }
    case 2:
        break;
    default:
        break;
    }

}