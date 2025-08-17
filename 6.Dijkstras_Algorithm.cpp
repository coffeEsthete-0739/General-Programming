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
    vector<vector<pair<int,int>>> graph(4);
    graph[0]={{1,4},{2,1}};
    graph[1]={{3,1}};
    graph[2]={{1,2},{3,5}};
    Dijkstra(graph,0);
}
