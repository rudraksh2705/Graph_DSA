#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
void dfs(vector<vector<int>> &adj, int u, vector<bool> &visited)
{
    ans.push_back(u);
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (visited[adj[u][i]])
            continue;
        dfs(adj, adj[u][i], visited);
    }
}

int main()
{
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<bool> visited(adj.size(), false);
    dfs(adj, 0, visited);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}