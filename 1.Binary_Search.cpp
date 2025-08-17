#include <iostream>
using namespace std;
int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1; 
    }

    int mid = (low + high) / 2;

    if (arr[mid] == key) {
        return mid; 
    }
    else if (key < arr[mid]) {
        return binarySearch(arr, low, mid - 1, key);
    }
    else {
        return binarySearch(arr, mid + 1, high, key);
    }
}

int main() {
    int n, key;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result == -1)
        cout << "Element not found!" << endl;
    else
        cout << "Element found at index " << result << endl;

    return 0;
}
