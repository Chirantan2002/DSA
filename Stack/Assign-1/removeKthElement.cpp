#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void removeElementsFromTop(stack<int> &st, int idx)
{
    stack<int> temp;
    int curr_idx = 0;
    while (!st.empty() && curr_idx < idx)
    {
        if (curr_idx != idx - 1)
        {
            temp.push(st.top());
            st.pop();
        }
        else
        {
            st.pop();
        }
        curr_idx++;
    }
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
}

void printStack(stack<int> a)
{
    while (!a.empty())
    {
        cout << a.top() << " ";
        a.pop();
    }
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    printStack(st);
    cout << endl;
    removeElementsFromTop(st, 2);
    printStack(st);
}