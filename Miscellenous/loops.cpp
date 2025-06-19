#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter the value of n = ";
    cin >> n;

    int i, j, k;

    for (i = n; i > 0; i--)
    {
        for (j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (k = i+4; k <= 2*n - 1; k++)
        {
            cout << " ";
        }
        for (j = i; j > 0; j--)
        {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}