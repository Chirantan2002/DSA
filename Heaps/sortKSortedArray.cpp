#include <iostream>   // cout / cin
#include <vector>     // vector
#include <queue>      // priority_queue
#include <functional> // greater / less
using namespace std;

int main()
{
    vector<int> arr = {10, 9, 8, 7, 4, 70, 60, 50};
    int n = arr.size(), k = 4;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; ++i)
    {
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
        {
            arr[i - k] = minHeap.top();
            minHeap.pop();
        }
    }

    for (int i = n - k; i < n; i++)
    {
        arr[i] = minHeap.top();
        minHeap.pop();
    }

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}