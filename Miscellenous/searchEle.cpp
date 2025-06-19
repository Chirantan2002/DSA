#include <bits/stdc++.h>

using namespace std;

int searchElement(vector<int> arr, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 9;
    int n = arr.size();
    int result = 0;
    result = searchElement(arr, n, k);
    cout << result;
    return 0;
}