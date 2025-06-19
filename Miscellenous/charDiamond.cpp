#include <bits/stdc++.h>

using namespace std;

int main()
{
    int no_of_line = 7;

    //1st half of the diamond
    for (int i = 1; i <= no_of_line; i++)
    {
        char ch = (2 * i) - 1;
        int space = no_of_line - i;
        for (int k = 0; k <= space; k++)
        {
            cout << " ";
        }
        for (int j = 0; j < ch; j++)
        {
            char result = (char)('A' + j);
            cout << result;
        }
        cout << "\n";
    }

    //2nd half of the diamond
    for (int i = no_of_line + 1; i <= (2 * no_of_line) - 1; i++)
    {
        char ch = 2 * (2 * no_of_line - i) - 1;
        int space = i - no_of_line;
        for (int k = 0; k <= space; k++)
        {
            cout << " ";
        }
        for (int j = 0; j < ch; j++)
        {
            char result = (char)('A' + j);
            cout << result;
        }
        cout << "\n";
    }

    return 0;
}