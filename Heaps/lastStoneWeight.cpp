#include <iostream>   // cout / cin
#include <vector>     // vector
#include <queue>      // priority_queue
#include <functional> // greater / less
#include <algorithm>
#include <unordered_map>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> pq;
    for (int ele : stones)
        pq.push(ele);

    while (pq.size() > 1)
    {
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        if (y > x)
            pq.push({abs(y - x)});
    }
    if (pq.size() == 1)
        return pq.top();
    else
        return 0;
}

int main()
{
    vector<int> arr = {2, 7, 4, 1, 8, 1};
    cout << lastStoneWeight(arr) << endl;
    return 0;
}