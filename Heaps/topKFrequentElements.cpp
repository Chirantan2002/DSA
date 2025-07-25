#include <iostream>   // cout / cin
#include <vector>     // vector
#include <queue>      // priority_queue
#include <functional> // greater / less
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> Map;
    for(int it : nums) Map[it]++;
    priority_queue<tuple<int, int>> pq;
    for(auto &[num, count] : Map) pq.push({count, num});
    vector<int> ans;
    for(int i = 0;i < k;++i){
        ans.push_back(get<1>(pq.top()));
        pq.pop();
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    for(int it : result) cout << it << " ";
    cout << endl;
    return 0;
}