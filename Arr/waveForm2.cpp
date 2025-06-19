#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the rows: ";
    cin >> n;
    int m;
    cout << "Enter the columns: ";
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

    for (int i = n - 1; i >= 0; i--) // !2nd wave-form printing
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            for (int j = m - 1; j >= 0; j--)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
}