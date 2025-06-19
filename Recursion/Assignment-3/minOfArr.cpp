#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minElement(vector<int> &arr, int idx)
{
    if (idx == arr.size())
        return INT_MAX;
    return min(arr[idx], minElement(arr, idx + 1));
}

int main()
{
    vector<int> arr = {4, 2, 6, 78, 2, 9, 34, 1, 5, 67, 76};
    cout << "Min element is: " << minElement(arr, 0);
}