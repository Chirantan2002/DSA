//* subsets of array which contains duplicates

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void go(vector<int> &nums, int idx, vector<int> &curr, vector<vector<int>> &ans)
{
    ans.push_back(curr);

    for (int i = idx; i < nums.size(); i++)
    {
        if (i != idx && nums[i] == nums[i - 1])
            continue;
        curr.push_back(nums[i]);
        go(nums, i + 1, curr, ans);
        curr.pop_back();
    }
}

vector<vector<int>> subsetWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    go(nums, 0, temp, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 3};

    vector<vector<int>> ans = subsetWithDup(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}