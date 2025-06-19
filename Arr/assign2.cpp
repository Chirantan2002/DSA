#include <iostream>

using namespace std;

int main()
{
    int n = 3;
    int arr[n][n];
    int brr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> brr[i][j];
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = arr[i][j] + brr[i][j];
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}