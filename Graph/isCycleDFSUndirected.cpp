#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isCycleDFS(unordered_map<int, vector<int>> &adjList, int u, vector<bool> &visited, int parent)
{
    visited[u] = true;

    for (auto &v : adjList[u])
    {
        if (v == parent)
            continue;
        if (visited[v])
            return true;
        if (isCycleDFS(adjList, v, visited, u))
            return true;
    }

    return false;
}

// Corrected function signature and logic
bool isCycle(int V, const vector<vector<int>>& edges)
{
    unordered_map<int, vector<int>> adjList;

    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && isCycleDFS(adjList, i, visited, -1))
            return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    int V = 6;

    if (isCycle(V, edges))
        cout << "Cycle detected in the graph." << endl;
    else
        cout << "No cycle in the graph." << endl;

    return 0;
}