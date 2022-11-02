#include <iostream>
#include <string>
#include "controller.h"
#include "view.h"
#include "playermodel.h"
#include "boardmodel.h"

using namespace std;

int main()
{
    Control control;
    View view;
    Player p1, p2;
    board boa;
    control.run(view, boa, p1, p2);
}