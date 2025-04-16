#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<pair<int, int>> adj[], int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V + 1, INT_MAX);

    pq.push({0, S});
    dist[S] = 0;

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int v = it.second;
            int w = it.first;
            if (dist[v] > dis + w)
            {
                dist[v] = dis + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int n, m, S;
    cout << "Enter the number of nodes (n), edges (m), and source node (S): ";
    cin >> n >> m >> S;

    vector<pair<int, int>> adj[n + 1];

    cout << "Enter the edges (u, v) and their weights (w):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    vector<int> shortPath = dijkstra(n, adj, S);

    cout << "Shortest paths from source node " << S << ":" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (shortPath[i] == INT_MAX)
            cout << "Node " << i << ": Unreachable" << endl;
        else
            cout << "Node " << i << ": " << shortPath[i] << endl;
    }

    return 0;
}
