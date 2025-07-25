#include <iostream>   // cout / cin
#include <vector>     // vector
#include <queue>      // priority_queue
#include <functional> // greater / less
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> findClosestElements(vector<int> &nums, int k, int x)
{
    int n = nums.size();
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i)
    {
        pq.push({abs(nums[i] - x), nums[i]});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> result;
    while (!pq.empty())
    {
        result.push_back(pq.top().second);
        pq.pop();
    }
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4, x = 3;
    vector<int> result = findClosestElements(arr, k, x);
    for (int it : result)
        cout << it << " ";
    cout << endl;
    return 0;
}