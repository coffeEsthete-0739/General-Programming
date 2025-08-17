#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int primMST(vector<vector<int>> graph) {
    int n = graph.size();
    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> mst(n, false);
    key[0] = 0;

    for(int i=0;i<n-1;i++){
        int u=-1;
        for(int j=0;j<n;j++)
            if(!mst[j] && (u==-1 || key[j]<key[u])) u=j;
        mst[u]=true;
        for(int v=0;v<n;v++)
            if(graph[u][v] && !mst[v] && graph[u][v]<key[v]){
                key[v]=graph[u][v];
                parent[v]=u;
            }
    }
    int cost=0;
    for(int i=1;i<n;i++) cost+=graph[i][parent[i]];
    return cost;
}

int main(){
    vector<vector<int>> graph = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };
    cout << "MST Cost: " << primMST(graph);
}
