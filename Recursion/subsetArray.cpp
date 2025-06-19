#include <iostream>
#include <string>
#include <vector>

using namespace std;

void subsetArray(vector<int> &arr, int idx, int n, vector<int> ans)
{
    if (idx == n)
    {
        if (ans.size() == 3)
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    if (ans.size() + (n - idx) < 3)
        return;
    subsetArray(arr, idx + 1, n, ans);
    ans.push_back(arr[idx]);
    subsetArray(arr, idx + 1, n, ans);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    vector<int> ans;
    subsetArray(arr, 0, n, ans);
}