#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the rows: ";
    cin >> n;
    int m;
    cout << "Enter the cols: ";
    cin >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    // !spiral printing algorithm
    // *[Leetcode - 54]
    int row_start = 0, row_end = n - 1, col_start = 0, col_end = m - 1;

    while (row_start <= row_end && col_start <= col_end)
    {
        for (int col = col_start; col <= col_end; col++) //* printing right path
        {
            cout << arr[row_start][col] << " ";
        }
        if (row_start > row_end || col_start > col_end)
            break;
        row_start++;

        for (int row = row_start; row <= row_end; row++) //* printing down path
        {
            cout << arr[row][col_end] << " ";
        }
        if (row_start > row_end || col_start > col_end)
            break;
        col_end--;

        for (int col = col_end; col >= col_start; col--) //* printing left path
        {
            cout << arr[row_end][col] << " ";
        }
        if (row_start > row_end || col_start > col_end)
            break;
        row_end--;

        for (int row = row_end; row >= row_start; row--) //* printing up path
        {
            cout << arr[row][col_start] << " ";
        }
        if (row_start > row_end || col_start > col_end)
            break;
        col_start++;
    }
}

// !Time Complexity - O(n*m)
// !Space Complexity - O(1)
// *if input comes as : 1 2 3 4 5 6 7 8 9
// *then output will be : 1 2 3 6 9 8 7 4 5