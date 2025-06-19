#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {1, 2, 4, 5};

    int sumOfArray = 0, n = arr.size(), sumOfN = 0;
    sort(begin(arr), end(arr));

    for (int i = 0; i < n; i++)
    {
        sumOfArray += arr[i];
    }

    int maxLimit = arr[n - 1];

    for (int i = 1; i <= maxLimit; i++)
    {
        sumOfN += i;
    }

    int res = sumOfN - sumOfArray;

    cout << res;

    return 0;
}