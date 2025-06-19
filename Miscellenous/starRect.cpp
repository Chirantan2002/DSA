#include <bits/stdc++.h>

using namespace std;

int main()
{
    int starRows = 4, starColumns = 5;

    for (int i = 1; i <= starRows; i++)
    {
        for (int j = 1; j <= starColumns; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }

    return 0;
}