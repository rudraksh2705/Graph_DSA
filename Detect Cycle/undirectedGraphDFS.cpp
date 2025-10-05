#include <iostream>
#include <vector>
using namespace std;

bool solve(int u, vector<vector<int>> &edges, int parent, vector<bool> &visited)
{
    visited[u] = true;
    for (int i = 0; i < edges[u].size(); i++)
    {
        if (edges[u][i] == parent)
            continue;
        if (visited[edges[u][i]])
            return true;
        if (solve(edges[u][i], edges, u, visited))
            return true;
    }
    return false;
}

int main()
{
    int V = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    vector<bool> visited(V, false);
    vector<vector<int>> adj(V);
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    bool flagged = false;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool flag = solve(i, adj, -1, visited);
            if (flag)
                cout << "true";
            flagged = true;
        }
    }
    cout << flagged;
}