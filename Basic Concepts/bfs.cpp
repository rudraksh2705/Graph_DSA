#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> ans;
void solve(vector<vector<int>> &adj, queue<int> &q, vector<bool> &visited)
{
    while (!q.empty())
    {
        int ele = q.front();
        ans.push_back(ele);
        visited[ele] = true;
        q.pop();
        for (auto el : adj[ele])
        {
            if (visited[el])
                continue;
            q.push(el);
            visited[el] = true;
        }
    }
}

int main()
{
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(0);
    solve(adj, q, visited);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}