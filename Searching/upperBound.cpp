#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11, 14};
    int n = arr.size();
    int low = 0, high = n - 1;
    int target = 13;
    vector<int>::iterator upperBound;
    int ans;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    upperBound = upper_bound(arr.begin(), arr.end(), target);

    cout << "Upperbound(using built-in) of the target is: " << upperBound - arr.begin() << "\n";
    cout << "Upperbound of the target is: " << ans;

    return 0;
}