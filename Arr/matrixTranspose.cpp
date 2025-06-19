#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    int arr[n][m];
    int result[m][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    /*
    ! Transpose by using extra array (Maybe sqaure or rectangular matrix)
    ? Time Complexity: O(n * m)
    ? Space Complexity: O(n * m)
    */

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    // for (int i = 0; i < m; i++) // 1st way to solve
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << arr[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    // for (int j = 0; j < m; j++) // 2nd way to solve
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    /*
    !Transpose without using extra space (Only applies for square matrix)
    ? Time Complexity: O(n^2)
    ? Space Complexity: O(1)
    */

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && j > i)
            {
                swap(arr[i][j], arr[j][i]);
            }
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
}