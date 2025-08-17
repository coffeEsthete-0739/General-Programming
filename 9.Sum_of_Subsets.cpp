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
    int n,target;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements:\n";
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << "Enter target sum: ";
    cin >> target;
    vector<int> subset;
    subsetSum(arr,target,0,subset);
}
