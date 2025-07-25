#include <iostream>   // cout / cin
#include <vector>     // vector
#include <queue>      // priority_queue
#include <functional> // greater / less
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> frequencySort(vector<int> &nums)
{
    unordered_map<int, int> map;
    for (int x : nums)
        map[x]++;
    sort(nums.begin(), nums.end(), [&](int a, int b)
         {
            if(map[a] != map[b]){
                return map[a] < map[b];
            }
            else{
                return a > b;
            } });
    return nums;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 3};
    vector<int> result = frequencySort(arr);
    for (int it : result)
        cout << it << " ";
    cout << endl;
    return 0;
}