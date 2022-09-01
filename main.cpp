#include "Core.h"

int main()
{

    Core core;

    vector<vector<string>> test = core.sql->GETTER("SELECT * FROM Account");

    cout << test[0][1] << endl;

    return 0;
}
