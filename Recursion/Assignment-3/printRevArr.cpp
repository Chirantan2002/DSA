#include <iostream>
#include <vector>

using namespace std;

void printRevArr(vector<int> &arr, int idx)
{
    if (idx == 0)
    {
        cout << arr[idx] << " ";
        return;
    }
    cout << arr[idx] << " ";
    printRevArr(arr, idx - 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printRevArr(arr, arr.size() - 1);
}