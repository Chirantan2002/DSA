#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {5, 1, 4, 3, -8, 20, 10, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) // number of passes
    {
        int minEle = INT_MAX;
        int minIndex = -1;
        for (int j = i; j < n; j++) // actual loop for sorting
        {
            if (minEle > arr[j])
            {
                minEle = arr[j];
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}