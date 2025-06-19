#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int> &s, int x)
{
    stack<int> temp;
    while (!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    s.push(x);
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

void displayRec(stack<int> &s)
{
    if(s.empty()) return;
    int x = s.top();
    cout << x << " ";
    s.pop();
    displayRec(s);
    s.push(x);
}

void displayRecRev(stack<int> &s)
{
    if(s.empty()) return;
    int x = s.top();
    s.pop();
    displayRecRev(s);
    cout << x << " ";
    s.push(x);
}

void pushAtAnyIndex(stack<int> &s, int idx, int x)
{
    stack<int> temp;
    while (s.size() > idx)
    { // for zero indexed stack
        temp.push(s.top());
        s.pop();
    }
    s.push(x);
    while (!temp.empty())
    {
        s.push(temp.top());
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

void pushAtBottomRecursively(stack<int> &s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int x = s.top();
    s.pop();
    pushAtBottomRecursively(s, val);
    s.push(x);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // s.pop();
    stack<int> temp;
    stack<int> temp2;
    // while (!s.empty())
    // {
    //     int x = s.top();
    //     s.pop();
    //     temp.push(x);
    // }
    // while (!temp.empty())
    // {
    //     int x = temp.top();
    //     temp.pop();
    //     cout << x << " ";
    // }
    cout << endl;
    // pushAtBottom(s, 100);
    // pushAtAnyIndex(s, 2, 77);
    displayRec(s); // printing top to bottom
    cout << endl;
    displayRecRev(s); // printing bottom to top
    // printStack(s);
    cout << endl;
    pushAtBottomRecursively(s, -88);
    printStack(s);
    return 0;
}