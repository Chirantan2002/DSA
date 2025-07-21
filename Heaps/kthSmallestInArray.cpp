#include <iostream>   // cout
#include <vector>     // vector
#include <queue>      // priority_queue
#include <functional> // greater / less
using namespace std;

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15, -1, -2, 45, -3};
    int n = arr.size(), k = 3;
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; ++i)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }
    cout << maxHeap.top() << endl;
    return 0;
}