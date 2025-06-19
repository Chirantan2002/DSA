#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> stockSpan(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n), span(n);
    ans[0] = -1, st.push(0);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
        span[i] = i - ans[i];
    }
    ans.clear();
    return span;
}

int main()
{
    vector<int> a = {100, 80, 60, 81, 70, 60, 75, 85};
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    vector<int> ans = stockSpan(a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}