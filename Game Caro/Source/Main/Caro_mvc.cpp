#include "client.h"
#include <iostream>
#include <string>
#include "controller.h"
#include "view.h"
#include "playermodel.h"
#include "boardmodel.h"
#include "helper.h"
#include "funcfile.h"

using namespace std;

int main()
{
    Control control;
    View view;
    Player p1, p2;
    board boa;
    Helper help;
    FuncFile ff;
    Client cli;

    control.run(view, boa, p1, p2, help, ff, cli);
    return 0;
}