#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter sorted elements:\n";
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << "Enter element to search: ";
    cin >> x;

    int result = binarySearch(arr, n, x);
    if (result != -1) cout << "Found at index " << result;
    else cout << "Not Found";
}
