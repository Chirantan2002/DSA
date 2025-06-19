#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), -1);
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> a = {8, 4, 6, 2, 3};
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    vector<int> ans = nextGreaterElement(a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}