#include <iostream>
#include <vector>

using namespace std;

int sum = 0;

int sumOfArr(vector<int> &arr, int idx)
{
    if (idx == arr.size() - 1)
        return arr[idx];
    return arr[idx] + sumOfArr(arr, idx + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    // int sum = 0;
    cout << sumOfArr(arr, 0);
}