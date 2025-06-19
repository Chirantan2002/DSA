#include <iostream>
#include <stack>
using namespace std;

bool match(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool isValid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (st.empty() || !match(st.top(), c))
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string s = ")()(";

    string res = (isValid(s)) ? "Valid!" : "Invalid!";
    cout << res << endl;
}