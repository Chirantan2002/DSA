#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter row no: ";
    cin >> n;
    int m;
    cout << "Enter col no: ";
    cin >> m;
    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Enter the " << i << " th row and " << j << " th "
                                                                "elements: ";
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}