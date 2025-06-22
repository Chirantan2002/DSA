#include <iostream>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    vector<int> arr = {3, -4, -7, 30, 7, -9, 2, 1, 6, -1};
    queue<int> q;
    int k = 3, n = arr.size();
    vector<int> ans;
    for(int i = 0;i < arr.size();i++){
        if(arr[i] < 0) q.push(i);
    }
    int idx = 0;
    while(idx <= n - k){
        while(!q.empty() && q.front() < idx) q.pop();
        if(q.empty() || q.front() >= idx + k) ans.push_back(0);
        else ans.push_back(arr[q.front()]);
        idx++;
    }
    for(int i = 0;i < arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = 0;i < ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}