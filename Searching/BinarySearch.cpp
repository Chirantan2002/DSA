#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int start, int end, int x)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (x == arr[mid])
            return mid;
        else if (x > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, 0, n - 1, key);

    result == -1 ? cout << "Not found!" : cout << "Found at index: " << result;

    return 0;
}