#include <iostream>
using namespace std;
#define INF 99999

int main(){
    int n=4;
    int graph[4][4] = {
        {0,5,INF,10},
        {INF,0,3,INF},
        {INF,INF,0,1},
        {INF,INF,INF,0}
    };
    int dist[4][4];
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
