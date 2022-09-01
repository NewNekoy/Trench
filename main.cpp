#include "Core.h"

void printDoubleVector(vector<vector<string>> test)
{
    for(int i = 0; i < test.size(); i++)
    {
        for (int j = 0; j < test[i].size(); j++)
        {
            cout << test[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

int main()
{

    Core core;

    vector<vector<string>> test = core.sql->GETTER("SELECT * FROM Account WHERE username!='SoyNeko'");

    printDoubleVector(test);

    return 0;
}
