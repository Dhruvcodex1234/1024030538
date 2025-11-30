#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter size of diagonal matrix: ");
    scanf("%d", &n);

    int diag[n];

    printf("Enter diagonal elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &diag[i]);

    printf("\nDiagonal Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                printf("%d ", diag[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }

    return 0;
}

