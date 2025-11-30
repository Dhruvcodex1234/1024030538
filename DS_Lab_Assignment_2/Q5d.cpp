#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter size of upper triangular matrix: ");
    scanf("%d", &n);

    int size = n * (n + 1) / 2;
    int upper[size];

    printf("Enter upper triangular elements:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &upper[i]);

    printf("\nUpper Triangular Matrix:\n");

    int k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i <= j)
                printf("%d ", upper[k++]);
            else
                printf("0 ");
        }
        printf("\n");
    }

    return 0;
}

