#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[6] = {2, 4, 1, 5, 3, 6};
    int firstMax = -1;
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] > firstMax)
            firstMax = arr[i];
    }

    int secondMax = -1;

    for (int i = 0; i < 6; i++)
    {
        if (firstMax != arr[i])
        {
            secondMax = max(secondMax, arr[i]);
        }
    }

    cout << "Second max is: " << secondMax;
    return 0;
}