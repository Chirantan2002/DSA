#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int> &arr, int target, int idx)
{
    if (arr[idx] == target)
        return idx;
    if (idx == arr.size())
        return -1;
    return linearSearch(arr, target, idx + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 4;
    cout << "Target found at index: " << linearSearch(arr, target, 0);
}
