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
bool isCycle(int V, vector<vector<int>> &edges)
{
    vector<bool> visited(V, false);
    vector<vector<int>> adj(V);
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool flag = solve(i, adj, -1, visited);
            if (flag)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<bool> visited(adj.size(), false);
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            bool flag = solve(i, adj, -1, visited);
            if (flag)
                cout << "True";
        }
    }
    cout << "False";
}