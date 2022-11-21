#include "listaccount.h"

AccountList::AccountList()
{
    string dt;
    ifstream ifs("databse/AccountList.ini");
    if (!ifs.is_open())
    {
        cout << "khoi tao lai\n";
        /* create file*/
        ofstream ofs{ R"(database/AccountList.ini)" , ios::app};
        if (!ofs.is_open())
        {
            std::cerr << "Could not open file for writing!\n";
            return;
        }
        ofs << "";

        ofs.close();
    }
   
    ifs.close();
    
}

bool AccountList::addAccount(string accountNew, string passWord)
{

    string linkPlayerFile = "database/" + accountNew + ".ini";
    if (checkAccountExist(accountNew))
    {
        return 0;
    }

    ofstream ofs("database/AccountList.ini", ios::app);
    if (!ofs) {
        cerr << "Error: file not opened." << endl;
        
    }
    ofs << " " << accountNew;
    ofs.close();
    
    /* create player file */
    ofstream playerFile(linkPlayerFile.c_str());
    if (!playerFile.is_open()) {
        cerr << "Error: file not opened." << endl;
      
    }
    playerFile << accountNew << " " << passWord << " " << 0 << " " << 0 << " " << 0;

    playerFile.close();
    return 1;
}

bool AccountList::checkLogin(string account, string password)
{
    string linkPlayerFile = "database/" + account + ".ini";
    ifstream playerFile(linkPlayerFile.c_str());
    if (!playerFile.is_open()) {
        cerr << "Error: file not opened." << endl;
        return 0;
    }
    string data;
    playerFile >> data >> data;
    if (password == data) {
        playerFile.close();
        return 1;
    }
    playerFile.close();
    return 0;
}

bool AccountList::checkAccountExist(string account)
{
    ifstream ifs("database/AccountList.ini");
    string data;
    if (!ifs.is_open()) {
        cerr << "Error: file not opened." << endl;
    }
    ifs >> data;
    if (data == account) { return 1; }
    while (!ifs.eof()) {
        ifs >> data;
        if (data == account) { return 1; }
    }
    return 0;
}

void AccountList::update(string acc, int type) {
    string pass, data;
    int w, l, d, dt;
    string link = "database/" + acc + ".ini";
    ifstream ifs(link.c_str());
    if (!ifs.is_open()) {
        cerr << "Error: file not opened." << endl;
        return;
    }
    ifs >> data;
    ifs >> data; pass = data;
    ifs >> dt; w = dt;
    ifs >> dt; l = dt;
    ifs >> dt; d = dt;
    ifs.close();
    if (type == 1) { w = w + 1; }
    if (type == 2) { l = l + 1; }
    if (type == 3) { d = d + 1; }
    ofstream ofs(link.c_str());
    if (!ofs.is_open()) {
        cerr << "Error: file not opened." << endl;
        return;
    }
    ofs << acc << " " << pass << " " << w << " " << l << " " << d;
    ofs.close();
}