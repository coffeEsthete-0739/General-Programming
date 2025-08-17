#include <iostream>
using namespace std;

bool isSafe(int board[], int row, int col){
    for(int i=0;i<row;i++)
        if(board[i]==col || abs(board[i]-col)==abs(i-row))
            return false;
    return true;
}

void solve(int board[], int row, int n){
    if(row==n){
        for(int i=0;i<n;i++) cout << board[i] << " ";
        cout << endl;
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(board,row,col)){
            board[row]=col;
            solve(board,row+1,n);
        }
    }
}

int main(){
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    int board[n];
    solve(board,0,n);
}
