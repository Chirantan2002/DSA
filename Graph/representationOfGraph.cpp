#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 3}, {3, 0}};

    unordered_map<int, vector<int>> adj; // Using unordered_map to represent the adjacency list
    // Each key in the map is a vertex, and the value is a vector of adjacent vertices

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}