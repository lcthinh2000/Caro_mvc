#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

//
//#include "rapidjson/document.h"
//#include "rapidjson/istreamwrapper.h"
//#include "rapidjson/writer.h"
//#include "rapidjson/stringbuffer.h"
//#include "rapidjson/ostreamwrapper.h"

using namespace std;
//using namespace rapidjson;

class AccountList
{
public:
    AccountList();

    bool addAccount(string account, string passWord);

    bool checkLogin(string account, string password);

    bool checkAccountExist(string account);

    void update(string acc, int type);
};

#endif // ACCOUNTLIST_H
