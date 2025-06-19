#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11, 14};
    int low = 0, high = arr.size() - 1;
    int target = 7;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target)
            low = mid + 1;
        else if (arr[mid] > target)
            high = mid - 1;
        else
        {
            low = mid;
            high = mid - 1;
        }
    }

    cout << target << " will insert in between index " << high << " & " << low;

    return 0;
}