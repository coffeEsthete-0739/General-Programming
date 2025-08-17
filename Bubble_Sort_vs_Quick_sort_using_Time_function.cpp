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
    int arr1[] = {5,2,9,1,7,6};
    int arr2[] = {5,2,9,1,7,6};
    int n=6;

    clock_t start = clock();
    bubbleSort(arr1,n);
    cout << "Bubble Sort Time: " << (double)(clock()-start)/CLOCKS_PER_SEC << endl;

    start = clock();
    quickSort(arr2,0,n-1);
    cout << "Quick Sort Time: " << (double)(clock()-start)/CLOCKS_PER_SEC << endl;
}
