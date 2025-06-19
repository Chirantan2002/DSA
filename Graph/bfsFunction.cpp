#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void BFS(unordered_map<int, vector<int>> &adj, int src, vector<bool> &visited, vector<int> &bfsResult)
{
    queue<int> que;
    que.push(src);       // Start BFS from the source vertex
    visited[src] = true; // Mark the source vertex as visited
    while (!que.empty())
    {
        int curr_node = que.front();    // Get the front node from the queue
        que.pop();                      // Remove the front node from the queue
        bfsResult.push_back(curr_node); // Add the current node to the BFS result
        for (auto neighbor : adj[curr_node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true; // Mark the neighbor as visited
                que.push(neighbor);       // Add the neighbor to the queue for further exploration
            }
        }
    }
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}};
    int V = 5;                           // Number of vertices
    unordered_map<int, vector<int>> adj; // Using unordered_map to represent the adjacency list
    for (auto edge : edges)
    {
        int src = edge[0];
        int dest = edge[1];
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    vector<bool> visited(V, false);
    vector<int> bfsResult;
    BFS(adj, 0, visited, bfsResult);
    cout << "BFS Traversal starting from vertex 0: ";
    for (int vertex : bfsResult)
    {
        cout << vertex << " ";
    }
    cout << endl;
    return 0;
}