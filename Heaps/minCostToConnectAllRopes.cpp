#include <iostream>   // cout / cin
#include <vector>     // vector
#include <queue>      // priority_queue
#include <functional> // greater / less
#include <algorithm>
#include <unordered_map>
using namespace std;

/*

An array of ropes is given where arr[i] = length of the rope [i], task is to join all the ropes with the min cost possible. You can connect only 2 ropes at a time with the cost being the sum of length of these ropes.

*/

int main()
{
    vector<int> ropes = {2, 7, 4, 1, 8};
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(int rope : ropes) min_heap.push(rope);
    int cost = 0;
    while(min_heap.size() > 1){
        int a = min_heap.top();
        min_heap.pop();
        int b = min_heap.top();
        min_heap.pop();
        cost += (a + b);
        min_heap.push(a + b);
    }
    cout << cost << endl;
    return 0;
}

// Time Complexity - O(nlogn)
// Space Complexity - O(n)