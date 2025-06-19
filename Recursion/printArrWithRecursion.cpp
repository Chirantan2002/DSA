//* Traversing an array using recursion & printing all elements ---->

#include <iostream>
#include <vector>

using namespace std;

int count = 0;

void printEle(vector<int> &arr, int idx)
{
    int n = arr.size();
    if (idx == n)
        return;
    cout << arr[idx] << " ";
    count++;
    printEle(arr, idx + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int idx = 0;
    printEle(arr, idx);
    cout << endl
         << endl
         << "Total element count: " << count;
}