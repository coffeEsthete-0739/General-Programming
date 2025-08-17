#include <iostream>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}
void quickSort(int arr[], int low, int high) {
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr1[n], arr2[n];
    cout << "Enter elements:\n";
    for(int i=0;i<n;i++){ 
        cin >> arr1[i]; 
        arr2[i]=arr1[i]; 
    }

    clock_t start = clock();
    bubbleSort(arr1,n);
    cout << "Bubble Sort Time: " << (double)(clock()-start)/CLOCKS_PER_SEC << endl;

    start = clock();
    quickSort(arr2,0,n-1);
    cout << "Quick Sort Time: " << (double)(clock()-start)/CLOCKS_PER_SEC << endl;
}
