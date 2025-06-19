#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

bool isCycleBFS(unordered_map<int, vector<int>> &adj, int src, vector<int>& visited, int parent){
    queue<pair<int, int>> que;
    que.push({src, -1});
    visited[src] = true;
    while(!que.empty()){
        pair<int, int> P = que.front();
        que.pop();
        int node = P.first;
        int parent = P.second;
        for(auto &it: adj[node]){
            if(!visited[it]){
                visited[it] = true;
                que.push({it, node});
            }
            else if(it != parent){
                return true;
            }
        }
    }
    return false;
}


bool isCycle(int V, const vector<vector<int>> &edges)
{
    vector<int> visited(V, false);
    unordered_map<int, vector<int>> adj;

    for (auto &edge : edges)
    {
        int src = edge[0];
        int dest = edge[1];
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    for(int i = 0;i < 6;i++){
        if(!visited[i] && isCycleBFS(adj, i, visited, -1)){
            return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {3, 4}, {3, 5}, {4, 5}};
    int V = 6;

    if (isCycle(V, edges))
    {
        cout << "Cycle detected in the graph." << endl;
    }
    else
    {
        cout << "No cycle in the graph." << endl;
    }
    return 0;
}