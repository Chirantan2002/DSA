#include <iostream>   // cout
#include <vector>     // vector
#include <queue>      // priority_queue
#include <functional> // greater
using namespace std;

int main()
{
    priority_queue<int> pq; // Max heap by default
    pq.push(10);
    pq.push(20);
    pq.push(14);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
}