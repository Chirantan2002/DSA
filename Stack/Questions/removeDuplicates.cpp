#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string removeDuplicates(string &s)
{
    stack<char> st;
    string res;
    for (char c : s)
    {
        if (st.empty() || st.top() != c)
        {
            st.push(c);
        }
        else if (!st.empty() && st.top() == c)
        {
            continue;
        }
    }
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string s = "aaabbcddaabffg";

    cout << removeDuplicates(s) << endl; //* abcdabfg (Output)
}