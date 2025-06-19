#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 4;

// Recursuve Approach - 1
// void combinationSum(vector<int> res, vector<int> arr, int n, int target, int idx)
// {
//     if (target == 0)
//     {
//         for (int i = 0; i < res.size(); i++)
//         {
//             cout << res[i] << " ";
//         }
//         cout << endl;
//         return;
//     }

//     if (target < 0)
//         return;

//     for (int i = idx; i < n; i++)
//     {
//         res.push_back(arr[i]);
//         combinationSum(res, arr, n, target - arr[i], i);
//         res.pop_back();
//     }
// }

// Recursive Approach - 2
void findCombination(vector<int> res, vector<int> &arr, vector<vector<int>> &ans, int target, int idx)
{
    if (idx == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(res);
        }
        return;
    }
    if (arr[idx] <= target)
    {
        res.push_back(arr[idx]);
        findCombination(res, arr, ans, target - arr[idx], idx);
        res.pop_back();
    }

    findCombination(res, arr, ans, target, idx + 1);
}

int main()
{
    // generate("");
    vector<int> arr = {2, 3, 5};
    int target = 8;
    vector<int> res;
    vector<vector<int>> ans;
    findCombination(res, arr, ans, target, 0);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    // combinationSum(res, arr, 3, target, 0);
}