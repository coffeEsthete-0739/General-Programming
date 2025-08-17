#include <iostream>
#include <vector>
using namespace std;

void subsetSum(vector<int> &arr, int target, int i, vector<int> &subset){
    int sum=0;
    for(int x:subset) sum+=x;
    if(sum==target){
        for(int x:subset) cout<<x<<" ";
        cout<<endl;
        return;
    }
    if(i>=arr.size() || sum>target) return;

    subset.push_back(arr[i]);
    subsetSum(arr,target,i+1,subset);
    subset.pop_back();
    subsetSum(arr,target,i+1,subset);
}

int main(){
    vector<int> arr={3,4,5,2};
    int target=7;
    vector<int> subset;
    subsetSum(arr,target,0,subset);
}
