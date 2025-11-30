#include <stdio.h>

struct term {
    int r, c, v;
};

int main() {
    int n1, n2, i, j, k = 0;

    printf("Enter non-zero elements of matrix A: ");
    scanf("%d", &n1);

    printf("Enter non-zero elements of matrix B: ");
    scanf("%d", &n2);

    struct term A[n1], B[n2], C[n1 * n2];

    printf("Enter A (row col val):\n");
    for (i = 0; i < n1; i++)
        scanf("%d %d %d", &A[i].r, &A[i].c, &A[i].v);

    printf("Enter B (row col val):\n");
    for (i = 0; i < n2; i++)
        scanf("%d %d %d", &B[i].r, &B[i].c, &B[i].v);

    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            if (A[i].c == B[j].r) {
                C[k].r = A[i].r;
                C[k].c = B[j].c;
                C[k].v = A[i].v * B[j].v;
                k++;
            }
        }
    }

    printf("\nMultiplication Result (not merged):\n");
    for (i = 0; i < k; i++)
        printf("%d %d %d\n", C[i].r, C[i].c, C[i].v);

    return 0;
}

