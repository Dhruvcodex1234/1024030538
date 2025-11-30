#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) arr[k++] = (L[i]<=R[j])?L[i++]:R[j++];
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l<r) {
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l-1;
    for(int j=l;j<r;j++) {
        if(arr[j]<pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quickSort(int arr[], int l, int r) {
    if(l<r) {
        int pi = partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

void printArray(int arr[], int n) {
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;

    int a1[5]; for(int i=0;i<n;i++) a1[i]=arr[i];
    selectionSort(a1,n); printArray(a1,n);

    int a2[5]; for(int i=0;i<n;i++) a2[i]=arr[i];
    insertionSort(a2,n); printArray(a2,n);

    int a3[5]; for(int i=0;i<n;i++) a3[i]=arr[i];
    bubbleSort(a3,n); printArray(a3,n);

    int a4[5]; for(int i=0;i<n;i++) a4[i]=arr[i];
    mergeSort(a4,0,n-1); printArray(a4,n);

    int a5[5]; for(int i=0;i<n;i++) a5[i]=arr[i];
    quickSort(a5,0,n-1); printArray(a5,n);
}

