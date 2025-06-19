#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    int arr[n][n];
    int res[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    //* step - 1: transpose of the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
                swap(arr[i][j], arr[j][i]);
        }
    }

    //* step - 2: reverse the rows one by one
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n / 2; i++)
        {
            swap(arr[i][j], arr[n - i - 1][j]);
        }
    }

    //* step - 3: print the matrix after 90 degree anti clockwise rotation
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}