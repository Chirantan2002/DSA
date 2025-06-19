#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int n = heights.size();
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] > heights[i]))
        {
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            ans = max(ans, h * w);
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights);
}