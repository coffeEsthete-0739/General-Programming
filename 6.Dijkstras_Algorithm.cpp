#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstra(vector<vector<pair<int,int>>> &graph, int src){
    int n = graph.size();
    vector<int> dist(n, 1e9);
    dist[src]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d>dist[u]) continue;
        for(auto [v,w]: graph[u]){
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=0;i<n;i++) cout << "Dist to " << i << " = " << dist[i] << endl;
}

int main(){
    int n,e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;
    vector<vector<pair<int,int>>> graph(n);
    cout << "Enter edges (u v w):\n";
    for(int i=0;i<e;i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    dijkstra(graph,src);
}
