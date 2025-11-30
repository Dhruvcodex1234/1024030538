#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int l = 2*i+1, r = 2*i+2, mx = i;
    if (l<n && arr[l] > arr[mx]) mx = l;
    if (r<n && arr[r] > arr[mx]) mx = r;
    if (mx != i) {
        swap(arr[i], arr[mx]);
        heapify(arr, n, mx);
    }
}

void heapSort(int arr[], int n) {
    for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
    for(int i=n-1;i>=0;i--) {
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}

int main() {
    int arr[] = {5,2,8,4,1};
    int n = 5;

    heapSort(arr,n);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
}

