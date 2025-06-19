#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> previousGreaterElements(vector<int> &nums)
{
    stack<int> st;
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? 1 : st.top() - i;
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 2, 3};
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    vector<int> ans = previousGreaterElements(a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}