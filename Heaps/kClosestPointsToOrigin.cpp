#include <iostream>   // cout / cin
#include <vector>     // vector
#include <queue>      // priority_queue
#include <functional> // greater / less
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    int row = points.size(), col = points[0].size();
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < row; ++i)
    {
        int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        pq.push({dist, {points[i][0], points[i][1]}});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<vector<int>> result;
    while (!pq.empty())
    {
        result.push_back({pq.top().second.first, pq.top().second.second});
        pq.pop();
    }
    return result;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {-2, 2}};
    int k = 1;
    vector<vector<int>> result = kClosest(arr, k);
    for (auto it : result)
        for (auto x : it)
            cout << x << " ";
    cout << endl;
    return 0;
}