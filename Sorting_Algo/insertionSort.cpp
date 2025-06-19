#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {5, 1, 4, 3, -8, 20, 10, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) // number of passes
    {
        int j = i + 1;
        while (j >= 1 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}