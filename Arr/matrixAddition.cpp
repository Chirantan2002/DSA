#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int arr[2][3] = {{1, 2, 3},
                     {4, 5, 6}};

    int brr[2][3] = {{7, 8, 9},
                     {10, 11, 12}};

    // int result[2][3];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            brr[i][j] = arr[i][j] + brr[i][j];
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }
}