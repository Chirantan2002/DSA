#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {0, 1, 2, 3, 4};
    int n = arr.size() - 1;
    int low = 0, high = n - 1, missing = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == mid)
            low = mid + 1;
        else
        {
            missing = mid;
            high = mid - 1;
        }
    }

    cout << missing;
    return 0;
}