#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter size of lower triangular matrix: ");
    scanf("%d", &n);

    int size = n * (n + 1) / 2;
    int lower[size];

    printf("Enter lower triangular elements:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &lower[i]);

    printf("\nLower Triangular Matrix:\n");

    int k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i >= j)
                printf("%d ", lower[k++]);
            else
                printf("0 ");
        }
        printf("\n");
    }

    return 0;
}

