#include <bits/stdc++.h>

using namespace std;

int squareRoot(int x)
{
    int low = 0, high = x;
    if (x < 2)
        return x;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid == x / mid)
        {
            return mid;
        }
        else if (mid > x / mid)
        {

            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return high;

    //Mentos Approach O(1)
    // return abs(sqrt(x));
}

int main()
{
    int x = 12;
    int res = 0;
    res = squareRoot(x);

    cout << "The sqrt is(abs): " << res;
    return 0;
}