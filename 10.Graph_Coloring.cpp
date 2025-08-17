#include <iostream>
using namespace std;

bool isSafe(int graph[4][4], int color[], int node, int c, int n){
    for(int i=0;i<n;i++)
        if(graph[node][i] && color[i]==c) return false;
    return true;
}

bool solve(int graph[4][4], int m, int color[], int node, int n){
    if(node==n){
        for(int i=0;i<n;i++) cout << color[i] << " ";
        cout << endl;
        return true;
    }
    for(int c=1;c<=m;c++){
        if(isSafe(graph,color,node,c,n)){
            color[node]=c;
            if(solve(graph,m,color,node+1,n)) return true;
            color[node]=0;
        }
    }
    return false;
}

int main(){
    int graph[4][4]={{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
    int color[4]={0};
    solve(graph,3,color,0,4);
}
