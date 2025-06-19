#include <iostream>
#include <climits>
// #include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[3][3] = {{3, 5, 8},
                     {7, 9, 6},
                     {4, 1, 2}};

    int maxElement = arr[0][0];
    int secondMaxElement = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] > maxElement)
            {
                secondMaxElement = maxElement;
                maxElement = arr[i][j];
            }
            else if (arr[i][j] > secondMaxElement && arr[i][j] != maxElement)
            {
                secondMaxElement = arr[i][j];
            }
        }
    }
    
    cout << "The max element is: " << maxElement;
    cout << "\nThe second max element is: " << secondMaxElement;

    return 0;
}