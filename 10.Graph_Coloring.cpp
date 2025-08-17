#include <iostream>
using namespace std;

bool isSafe(int graph[10][10], int color[], int node, int c, int n){
    for(int i=0;i<n;i++)
        if(graph[node][i] && color[i]==c) return false;
    return true;
}

bool solve(int graph[10][10], int m, int color[], int node, int n){
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
    int n,m;
    cout << "Enter number of vertices: ";
    cin >> n;
    int graph[10][10];
    cout << "Enter adjacency matrix:\n";
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> graph[i][j];
    cout << "Enter number of colors: ";
    cin >> m;
    int color[10]={0};
    if(!solve(graph,m,color,0,n)) cout << "No solution!";
}
