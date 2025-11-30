#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 7, 11, 19, 23, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 19;

    int index = binarySearch(arr, n, key);

    if (index != -1)
        printf("Element found at index %d", index);
    else
        printf("Element not found");

    return 0;
}

