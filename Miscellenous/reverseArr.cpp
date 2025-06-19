#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0, end = 8;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    for (int i = 0; i < 9; i++)
        cout << arr[i] << " ";

    return 0;
}
