#include <stdio.h>

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = 7;
    int i, j, count = 0, flag;

    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag)
            count++;
    }

    printf("Distinct elements = %d", count);
    return 0;
}

