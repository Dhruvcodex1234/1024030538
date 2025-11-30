#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter size of tri-diagonal matrix: ");
    scanf("%d", &n);

    int tri[3*n - 2];

    printf("Enter tri-diagonal elements:\n");
    for (i = 0; i < 3*n - 2; i++)
        scanf("%d", &tri[i]);

    printf("\nTri-Diagonal Matrix:\n");
    int k = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)              // main diagonal
                printf("%d ", tri[i]);
            else if (j == i + 1)     // upper
                printf("%d ", tri[n + i]);
            else if (i == j + 1)     // lower
                printf("%d ", tri[2*n - 1 + j]);
            else
                printf("0 ");
        }
        printf("\n");
    }

    return 0;
}

