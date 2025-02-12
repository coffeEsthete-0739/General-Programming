#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int start, vector<int> adj[], int n)
{
    vector<int> visited(n + 1, 0);
    visited[start] = 1;
    vector<int> bfs;
    queue<int> q;
    q.push(start);
    bfs.push_back(start);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
                bfs.push_back(it);
            }
        }
    }
    return bfs;
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes & edges: ";
    cin >> n >> m;

    vector<int> adj[n + 1];

    cout << "Enter the edges: " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter the starting node: " << endl;
    cin >> start;

    if (start < 1 || start > n)
    {
        cout << "Invalid starting node!" << endl;
        return 1;
    }

    vector<int> bfs = BFS(start, adj, n);

    cout << "BFS traversal: " << endl;
    for (auto it : bfs)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
