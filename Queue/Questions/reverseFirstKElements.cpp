// Reversing first K elements in a Queue
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseKElements(queue<int> &q, int k)
{
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        int x = q.front();
        q.pop();
        st.push(x);
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < q.size() - k; i++)
    {
        int x = q.front();
        q.pop();
        q.push(x);
    }
}

void display(queue<int> &q)
{
    for (int i = 0; i < q.size(); i++)
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
        q.push(x);
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    display(q);
    reverseKElements(q, 3);
    display(q);
}