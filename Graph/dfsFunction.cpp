#include <iostream>
#include <vector>
#include <unordered_map> // Add this include
using namespace std;

void DFS(unordered_map<int, vector<int>>& adj, int src, vector<bool>& visited, vector<int>& dfsResult)
{
    if (visited[src]) return;   // Fixed typo here
                                // If the vertex is already visited, return
                                
    visited[src] = true;        // Mark the current vertex as visited
    dfsResult.push_back(src);   // Add the current vertex to the DFS result
    for (auto neighbor : adj[src])
    {
        if (!visited[neighbor])
        {
            DFS(adj, neighbor, visited, dfsResult); // Recursively visit the unvisited neighbors
        }
    }
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}};
    int V = 5; // Number of vertices

    unordered_map<int, vector<int>> adj; // Using unordered_map to represent the adjacency list

    for (auto edge : edges)
    {
        int src = edge[0];
        int dest = edge[1];
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    vector<bool> visited(V, false); // Vector to keep track of visited vertices
    vector<int> dfsResult;

    DFS(adj, 0, visited, dfsResult);

    cout << "DFS Traversal starting from vertex 0: ";
    for (int vertex : dfsResult)
    {
        cout << vertex << " "; // Print the DFS traversal result
    }
    cout << endl;

    return 0;
}