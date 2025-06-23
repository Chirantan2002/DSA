#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reorderQueue(queue<int> &q){
    stack<int> st;
    int n = q.size();
    for(int i = 0;i < n / 2;i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    for(int i = 0;i < n / 2;i++){
        int x = q.front();
        q.pop();
        q.push(x);
    }
    for(int i = 0;i < n / 2;i++){
        st.push(q.front());
        q.pop();
    }
    for(int i = 0;i < n / 2;i++){
        q.push(st.top());
        q.push(q.front());
        st.pop();
        q.pop();
    }

}

void display(queue<int> &q){
    for(int i = 0;i < q.size();i++){
        int x = q.front();
        cout << x << " ";
        q.pop();
        q.push(x);
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);

    reorderQueue(q);
    display(q);
}