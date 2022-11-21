#include "controller.h"

Control::Control()
{
}

bool Control::checkwin(Player pl, board boa, Helper help) {
    if ( help.checkcolumn(pl, boa)==true || help.checkrow(pl, boa)==true ||
         help.checkdiagonal1(pl, boa)==true || help.checkdiagonal2(pl, boa)==true) {
            return true;
    }
}

void Control::listpl(View view, board boa, Player p1, Player p2, Helper help, FuncFile ff, Client cli) {
    ifstream ifs("listplayer.ini");
    string data;
    int static cm;
    Player pln;
    system("cls");
    if (!ifs) {
        cerr << "Error: file not opened." << endl;
        return;
    }
    cout << "List Player:\n";
    ifs >> data;
    while (!ifs.eof()) {
        
        cout << "Name: " << data << endl;
        ifs >> data; //ifs >> data;
        cout << "Win: " << data;
        ifs >> data; //ifs >> data;
        cout << "; Lose: " << data;
        ifs >> data; //ifs >> data;
        cout << "; Draw: " << data << endl;
        ifs >> data;
    }
    cout << "\n1. Add Player\n";
    cout << "2. Reset list\n";
    cout << "3. Exit\n";
    cout << "Command: ";
    cin >> cm;
    switch (cm) {
    case 1:
        view.addplay(pln);
        ff.addPlayer(pln);
        listpl(view, boa, p1, p2, help, ff, cli);
    case 2:
        ff.resetlist();
        listpl(view, boa, p1, p2, help, ff, cli);
    case 3:
        run(view, boa, p1, p2, help, ff, cli);
    default:
        break;
    }
}

void Control::replay(int a, int c, View view, board boa, Player p1, Player p2, Helper help, FuncFile ff, Client cli) {
    ifstream ifs("history.ini");
    string data, name;
    string n1, n2;
    char kh, tam, nex;
    int wi, he;
    int rt, dt;
    int turn, td1, td2;
    board boar;
    if (!ifs) {
        cerr << "Error: file not opened." << endl;
        return;
    }
    switch (a) {
    case 1:
        ifs >> data; ifs >> data; ifs >> data;
        n1 = data;
        ifs >> data; ifs >> data; ifs >> data;
        n2 = data;
        ifs >> data; ifs >> data; ifs >> dt;
        wi = dt;
        ifs >> data; ifs >> dt;
        he = dt;
        boar.set_w(wi);
        boar.set_h(he);
        system("cls");
        view.InfoRepl(n1, n2, wi, he);
        
        for (int i = 0; i < c; i++) {
            Sleep(3000);
            system("cls");
            ifs >> data; ifs >> dt;
            turn = dt;
            ifs >> data; ifs >> data;
            name = data;
            ifs >> data; ifs >> tam;
            kh = tam;
            ifs >> data; ifs >> dt;
            td1 = dt;
            ifs >> dt;
            td2 = dt;
            view.repl(name, kh, td1, td2, turn, boar);
        }

        cout << endl;
        ifs >> data;
        while (!ifs.eof()) {
            cout << data << " ";
            ifs >> data;
        }

        ifs.close();
        cout << "\n\nPress 1 to return menu: "; cin >> rt;
        while (rt != 1) {
            cout << "\nwrong syntax, re-enter: "; cin >> rt;
        }
        run(view, boa, p1, p2, help, ff, cli);
    case 2:
        run(view, boa, p1, p2, help, ff, cli);
    default:
        break;
    }
}

void Control::playOnl(string acc, View view, board boa, Player p1, Player p2, Helper help, FuncFile ff, Client cli, AccountList acclist) {
    char KH;
    string rep, mes, plNum;
    string e1 = "Player 1 is winner";
    string e2 = "Player 2 is winner";
    int tdx, tdy, find, cm;
    Player pl1, pl2;
    boa.set_w(10); boa.set_h(10);
    cli.initClient();
    cli.createSocket();
    cli.listenReponse(rep);
    system("cls");
    cout << "MESSAGE from SERVER:\n\t" << rep;
    cli.listenReponse(rep);
    cout << rep;
    if (rep == "You are player 1 (X)\n") {
        KH = 'X';
        pl1.setKH(KH);
    }
    if (rep == "You are player 2 (O)\n") {
        KH = 'O';
        pl1.setKH(KH);
    }
    plNum = rep;
    cout << "\nHello " << acc << endl;
    pl1.setName(acc);
    cout << "\nPress 1 to find game: ";
    cin >> find;
    while (true) {
        if (find == 1) {
            break;
        }
        else {
            cout << "Wrong syntax, re-press: ";
            cin >> find;
        }
    }
    cli.sendMsg(acc);
    cout << "Waiting for other player...\n";
    
    while (true) {
        int checkRep = cli.listenReponse(rep);
        if (checkRep == 1&&rep!= "You are player 1 (X)\n"&&rep!= "You are player 2 (O)\n") {
            cout << "Other player already!\n";
            cout << "Other player: " << rep;
            pl2.setName(rep);
            string end1 = "\nPlayer " + pl1.getName() + " is winner!\n";
            string end2 = "\nPlayer " + pl2.getName() + " is winner!\n";
            if (pl1.getKH() == 'X') {
                pl2.setKH('O');
            }
            else {
                pl2.setKH('X');
            }
            cout << "\n\t Start game!\n";
            Sleep(1500);
            if (plNum == "You are player 1 (X)\n") {
                for (int i = 0; i < 51; i++) {
                    system("cls");
                    view.drawboard(boa);
                    pl1.turnOnl(boa, cli);
                    if (checkwin(pl1, boa, help) == true) {
                        system("cls");
                        view.drawboard(boa);
                        cout << end1;
                        acclist.update(pl1.getName(), 1);
                        cout << "\nPress 1 to exit: "; cin >> cm;
                        while (true) {
                            if (cm == 1) {
                                inAcc(acc, view, boa, p1, p2, help, ff, cli, acclist);
                            }
                            else {
                                cout << "Wrong syntax, re-press: ";
                                cin >> cm;
                            }
                        }
                    }
                    if (i == 50 && checkwin(pl1, boa, help) != true && checkwin(pl2, boa, help) != true) {
                        system("cls");
                        view.drawboard(boa);
                        cout << "\n2 player is draw!\n";
                        acclist.update(pl1.getName(), 3);
                        cout << "\nPress 1 to exit: "; cin >> cm;
                        while (true) {
                            if (cm == 1) {
                                inAcc(acc, view, boa, p1, p2, help, ff, cli, acclist);
                            }
                            else {
                                cout << "Wrong syntax, re-press: ";
                                cin >> cm;
                            }
                        }
                    }
                    system("cls");
                    view.drawboard(boa);
                    pl2.turnRep(boa, cli);
                    if (checkwin(pl2, boa, help) == true) {
                        system("cls");
                        view.drawboard(boa);
                        cout << end2;
                        acclist.update(pl1.getName(), 2);
                        cout << "\nPress 1 to exit: "; cin >> cm;
                        while (true) {
                            if (cm == 1) {
                                inAcc(acc, view, boa, p1, p2, help, ff, cli, acclist);
                            }
                            else {
                                cout << "Wrong syntax, re-press: ";
                                cin >> cm;
                            }
                        }
                    }
                    if (i == 50 && checkwin(pl1, boa, help) != true && checkwin(pl2, boa, help) != true) {
                        system("cls");
                        view.drawboard(boa);
                        cout << "\n2 player is draw!\n";
                        acclist.update(pl1.getName(), 3);
                        cout << "\nPress 1 to exit: "; cin >> cm;
                        while (true) {
                            if (cm == 1) {
                                inAcc(acc, view, boa, p1, p2, help, ff, cli, acclist);
                            }
                            else {
                                cout << "Wrong syntax, re-press: ";
                                cin >> cm;
                            }
                        }
                    }
                }
            }
            else {
                for (int i = 0; i < 51; i++) {
                    system("cls");
                    view.drawboard(boa);
                    pl2.turnRep(boa, cli);
                    if (checkwin(pl2, boa, help) == true) {
                        system("cls");
                        view.drawboard(boa);
                        cout << end2;
                        acclist.update(pl1.getName(), 2);
                        cout << "\nPress 1 to exit: "; cin >> cm;
                        while (true) {
                            if (cm == 1) {
                                inAcc(acc, view, boa, p1, p2, help, ff, cli, acclist);
                            }
                            else {
                                cout << "Wrong syntax, re-press: ";
                                cin >> cm;
                            }
                        }
                    }
                    if (i == 50 && checkwin(pl1, boa, help) != true && checkwin(pl2, boa, help) != true) {
                        system("cls");
                        view.drawboard(boa);
                        cout << "\n2 player is draw!\n";
                        acclist.update(pl1.getName(), 3);
                        cout << "\nPress 1 to exit: "; cin >> cm;
                        while (true) {
                            if (cm == 1) {
                                inAcc(acc, view, boa, p1, p2, help, ff, cli, acclist);
                            }
                            else {
                                cout << "Wrong syntax, re-press: ";
                                cin >> cm;
                            }
                        }
                    }
                    system("cls");
                    view.drawboard(boa);
                    pl1.turnOnl(boa, cli);
                    if (checkwin(pl1, boa, help) == true) {
                        system("cls");
                        view.drawboard(boa);
                        cout << end1;
                        acclist.update(pl1.getName(), 1);
                        cout << "\nPress 1 to exit: "; cin >> cm;
                        while (true) {
                            if (cm == 1) {
                                inAcc(acc, view, boa, p1, p2, help, ff, cli, acclist);
                            }
                            else {
                                cout << "Wrong syntax, re-press: ";
                                cin >> cm;
                            }
                        }
                    }
                    if (i == 50 && checkwin(pl1, boa, help) != true && checkwin(pl2, boa, help) != true) {
                        system("cls");
                        view.drawboard(boa);
                        cout << "\n2 player is draw!\n";
                        acclist.update(pl1.getName(), 3);
                        cout << "\nPress 1 to exit: "; cin >> cm;
                        while (true) {
                            if (cm == 1) {
                                inAcc(acc, view, boa, p1, p2, help, ff, cli, acclist);
                            }
                            else {
                                cout << "Wrong syntax, re-press: ";
                                cin >> cm;
                            }
                        }
                    }
                }
            }
               
        }
        continue;
    }
}

void Control::account(View view, board boa, Player p1, Player p2, Helper help, FuncFile ff, Client cli, AccountList acclist) {
    int cm, cm1;
    string acc, pass, data;
    
    system("cls");
    view.viewAcc();
    cout << "\nCommand: "; cin >> cm;
    switch (cm) {
    case 1:
        system("cls");
        cout << "\t\tLogin Account\n";
        cout << "\nAccount: "; cin >> acc;
        cout << "Password: "; cin >> pass;
        if (acclist.checkLogin(acc, pass)) {
            cout << "\nLogin successfully!!!\n";
            Sleep(1500);
            inAcc(acc, view, boa, p1, p2, help, ff, cli, acclist);
        }
        else {
            cout << "\nLogin failed!\n";
            Sleep(1500);
            account(view, boa, p1, p2, help, ff, cli, acclist);
        }
    case 2:
        system("cls");
        cout << "\t\tRegister new Account\n";
        cout << "\nAccount: "; cin >> acc;
        cout << "Password: "; cin >> pass;
        if (acclist.addAccount(acc,pass)) {
            cout << "\nRegister successfully!\n";
            Sleep(1500);
            account(view, boa, p1, p2, help, ff, cli, acclist);
        }
        else {
            cout << "\nRegister failed!\n";
            Sleep(1500);
            account(view, boa, p1, p2, help, ff, cli, acclist);
        }
    case 3:
        system("cls");
        view.listAcc();
        cout << "\nPress 1 to exit: ";
        cin >> cm1;
        while (true) {
            if (cm1 == 1) {
                account(view, boa, p1, p2, help, ff, cli, acclist);
            }
            else {
                cout << "Wrong syntax, re-press: ";
                cin >> cm1;
            }
        }
    case 4:
        run(view, boa, p1, p2, help, ff, cli);
    default:
        break;
    }
    
}

void Control::inAcc(string acc, View view, board boa, Player p1, Player p2, Helper help, FuncFile ff, Client cli, AccountList acclist) {
    int cm, cm1;
    string link, data;
    link = "database/" + acc + ".ini";
    ifstream ifs(link.c_str());
    system("cls");
    view.viewMenuAcc(acc);
    cout << "\nCommand: "; cin >> cm;
    switch (cm) {
    case 1:
        playOnl(acc, view, boa, p1, p2, help, ff, cli, acclist);
    case 2:
        system("cls");
        if (!ifs.is_open()) {
            cerr << "Error: file not opened." << endl;
            return;
        }
        cout << "\t\tInfo Player\n";
        cout << "\nAccount: "; ifs >> data; cout << data;
        cout << "\nPassword: "; ifs >> data; cout << data;
        cout << "\nWin: "; ifs >> data; cout << data;
        cout << "\nLose: "; ifs >> data; cout << data;
        cout << "\nDraw: "; ifs >> data; cout << data;
        ifs.close();
        cout << "\n\nPress 1 to exit: "; cin >> cm1;
        while (true) {
            if (cm1 == 1) {
                inAcc(acc, view, boa, p1, p2, help, ff, cli, acclist);
            }
            else {
                cout << "Wrong syntax, re-press: ";
                cin >> cm1;
            }
        }
    case 3:
        cli.closeSocket();
        account(view, boa, p1, p2, help, ff, cli, acclist);
    default:
        break;
    }
}

void Control::playGame(Player p1, Player p2, int w, int h, int count, board boa, FuncFile ff, View view, Helper help, Client cli){
    string n1, n2, re;
    int x, y, cm;
    p1.setKH('X');
    p2.setKH('O');
    system("cls");
    cout << "\t\tNEW GAME\n";
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
    ff.resetfile();
    ff.infoHis(p1, p2, boa);
    system("cls");
    view.drawboard(boa);
    for (int i = 0; i <= ((w * h) / 2); i++) {

        p1.turn(boa, x, y);
        ff.History(p1, count, x, y);
        count++;
        system("cls");
        view.drawboard(boa);
        if (checkwin(p1, boa, help) == true) {
            view.endgame(p1);
            re = "Player 1: " + p1.getName() + " is winner!";
            ff.result(re);
            cin >> cm;
            replay(cm, count, view, boa, p1, p2, help, ff, cli);
        }
        if (count == (w * h) && checkwin(p1, boa, help) != true) {
            cout << "2 player is draw!\n";
            re = "2 player is draw!";
            ff.result(re);
            cout << "\n1. Replay\n";
            cout << "2. Exit\n";
            cout << "Command: ";
            cin >> cm;
            replay(cm, count, view, boa, p1, p2, help, ff, cli);
        }

        p2.turn(boa, x, y);
        ff.History(p2, count, x, y);
        count++;
        system("cls");
        view.drawboard(boa);
        if (checkwin(p2, boa, help) == true) {
            view.endgame(p2);
            re = "Player 2: " + p2.getName() + " is winner!";
            ff.result(re);
            cin >> cm;
            replay(cm, count, view, boa, p1, p2, help, ff, cli);
        }
        if (count == (w * h) && checkwin(p2, boa, help) != true) {
            cout << "2 player is draw!";
            re = "2 player is draw!";
            ff.result(re);
            cout << "\n1. Replay\n";
            cout << "2. Exit\n";
            cout << "Command: ";
            cin >> cm;
            replay(cm, count, view, boa, p1, p2, help, ff, cli);
        }
    }
}

void Control::run(View view, board boa, Player p1, Player p2, Helper help, FuncFile ff, Client cli) {
    int static command;
    int count = 0;
    int w = 0, h = 0;
    AccountList acclist;
    string acc, pass;
    Player pln;
    system("cls");
    view.Menu();
    cin >> command;
    switch (command)
    {
    case 1:
        playGame(p1, p2, w, h, count, boa, ff, view, help, cli);
    case 2:
        account(view, boa, p1, p2, help, ff, cli, acclist);
    case 3:
        listpl(view, boa, p1, p2, help, ff, cli);
    case 4:
        exit(0);
    default:
        break;
    }

}
