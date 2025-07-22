#include <iostream>   // cout
#include <vector>     // vector
#include <queue>      // priority_queue
#include <functional> // greater / less
using namespace std;

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15, -1, -2, 45, -3};
    int n = arr.size(), k = 3;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; ++i)
    {
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    cout << minHeap.top() << endl;
    return 0;
}