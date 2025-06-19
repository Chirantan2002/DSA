#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {5, 1, 4, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int minEle = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minEle)
        {
            minEle = arr[i];
            minIndex = i;
        }
    }

    cout << minEle << "\n";
    cout << "Index is: " << minIndex;

    return 0;
}