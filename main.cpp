#include "Core.h"

void printDoubleVector(vector<vector<string>> test)
{
    for(size_t i = 0; i < test.size(); i++)
    {
        for (size_t j = 0; j < test[i].size(); j++)
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

    core.premice();

    return 0;
}
