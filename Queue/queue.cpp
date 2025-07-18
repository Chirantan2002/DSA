#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void displayQueue(queue<int> &q)
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

void reverseQueue(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        st.push(x);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    displayQueue(q);
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    reverseQueue(q);
}