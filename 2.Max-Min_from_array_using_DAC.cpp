#include <iostream>
using namespace std;

pair<int,int> findMinMax(int arr[], int low, int high) {
    if (low == high) return {arr[low], arr[low]};
    if (high == low + 1) 
        return {min(arr[low], arr[high]), max(arr[low], arr[high])};
    int mid = (low + high) / 2;
    auto left = findMinMax(arr, low, mid);
    auto right = findMinMax(arr, mid+1, high);
    return {min(left.first, right.first), max(left.second, right.second)};
}

int main() {
    int arr[] = {5, 8, 1, 9, 2, 7};
    int n = 6;
    auto ans = findMinMax(arr, 0, n-1);
    cout << "Min: " << ans.first << " Max: " << ans.second;
}
