#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter size of symmetric matrix: ");
    scanf("%d", &n);

    int size = n * (n + 1) / 2;
    int sym[size];

    printf("Enter lower triangular elements:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &sym[i]);

    printf("\nSymmetric Matrix:\n");

    int k = 0;
    int idx[n][n];

    k = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j <= i; j++)
            idx[i][j] = idx[j][i] = k++;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", sym[idx[i][j]]);
        printf("\n");
    }

    return 0;
}

