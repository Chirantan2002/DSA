//* max element of an array using recursion ---->

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// int maxElement(vector<int> &arr, int idx, int max)
// {
//     if (idx == arr.size())
//         return max;
//     if (max < arr[idx])
//         max = arr[idx];
//     return maxElement(arr, idx + 1, max);
// }

int maxElement(vector<int> &arr, int idx)
{
    if (idx == arr.size())
        return INT_MIN;
    return max(arr[idx], maxElement(arr, idx + 1));
}

int main()
{
    vector<int> arr = {100, 2545, 585, 4845, 48484, 52254, 85845, 684856, 56};
    int idx = 0;
    cout << "Max element is: " << maxElement(arr, idx);
}