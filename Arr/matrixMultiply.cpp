#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cout << "Enter the number of rows for 1st matrix: ";
    cin >> n;
    cout << "Enter the number of columns for 1st matrix: ";
    cin >> m;

    int p, q;
    cout << "Enter the number of rows for 2nd matrix: ";
    cin >> p;
    cout << "Enter the number of columns for 2nd matrix: ";
    cin >> q;

    if (m != p)
    {
        cout << endl;
        cout << "The matrices cannot be multiplied.";
    }

    else
    {
        int arr[n][m];
        int brr[p][q];
        int result[n][q];

        cout << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cin >> brr[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < q; j++)
            {
                result[i][j] = 0;
                for (int k = 0; k < p; k++)
                {
                    result[i][j] += arr[i][k] * brr[k][j];
                }
            }
        }

        cout << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
}