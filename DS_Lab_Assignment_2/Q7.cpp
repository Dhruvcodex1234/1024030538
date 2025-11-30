#include <stdio.h>

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = 5;
    int i, j, count = 0;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                count++;
        }
    }

    printf("Total inversions = %d", count);
    return 0;
}

