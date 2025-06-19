//* subset of array which doesn't contain duplicates

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void go(vector<int> &nums, int idx, vector<int> &curr, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(curr);
        return;
    }

    go(nums, idx + 1, curr, ans);
    curr.push_back(nums[idx]);
    go(nums, idx + 1, curr, ans);
    curr.pop_back();
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> curr;
    go(nums, 0, curr, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}