#include <iostream>
using namespace std;
#define INF 99999

int main(){
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    int graph[n][n];
    cout << "Enter adjacency matrix (use " << INF << " for no edge):\n";
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> graph[i][j];
    int dist[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) dist[i][j]=graph[i][j];

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    cout << "All Pairs Shortest Paths:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout << dist[i][j] << " ";
        cout << endl;
    }
}
