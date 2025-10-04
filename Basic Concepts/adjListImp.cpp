#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void print(vector<vector<int>> &graph, int n)
{
    map<int, vector<int>> adj;
    for (int i = 0; i < graph.size(); i++)
    {
        adj[graph[i][0]].push_back(graph[i][1]);
    }

    for (auto ele : adj)
    {
        cout << ele.first << " " << "->" << " ";
        for (int el : adj[ele.first])
        {
            cout << el << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> graph = {{1, 0}, {2, 0}, {2, 1}, {3, 1}};
    print(graph, graph.size());
}