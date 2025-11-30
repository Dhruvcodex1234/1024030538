#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 5, 6}; // missing 4
    int n = 6;
    int i;

    for (i = 0; i < n - 1; i++) {
        if (arr[i + 1] != arr[i] + 1) {
            printf("Missing number: %d", arr[i] + 1);
            return 0;
        }
    }

    printf("No missing number");
    return 0;
}

