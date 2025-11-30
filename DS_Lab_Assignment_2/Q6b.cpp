#include <stdio.h>

struct term {
    int r, c, v;
};

int main() {
    int n1, n2, i, j, k = 0;

    printf("Enter number of non-zero elements of first matrix: ");
    scanf("%d", &n1);

    printf("Enter number of non-zero elements of second matrix: ");
    scanf("%d", &n2);

    struct term a[n1], b[n2], sum[n1 + n2];

    printf("Enter first matrix triplets:\n");
    for (i = 0; i < n1; i++)
        scanf("%d %d %d", &a[i].r, &a[i].c, &a[i].v);

    printf("Enter second matrix triplets:\n");
    for (i = 0; i < n2; i++)
        scanf("%d %d %d", &b[i].r, &b[i].c, &b[i].v);

    i = j = 0;

    while (i < n1 && j < n2) {
        if (a[i].r == b[j].r && a[i].c == b[j].c) {
            sum[k] = a[i];
            sum[k].v = a[i].v + b[j].v;
            i++; j++; k++;
        }
        else if (a[i].r < b[j].r || 
                (a[i].r == b[j].r && a[i].c < b[j].c)) {
            sum[k++] = a[i++];
        }
        else {
            sum[k++] = b[j++];
        }
    }

    while (i < n1) sum[k++] = a[i++];
    while (j < n2) sum[k++] = b[j++];

    printf("\nSum Matrix:\n");
    for (i = 0; i < k; i++)
        printf("%d %d %d\n", sum[i].r, sum[i].c, sum[i].v);

    return 0;
}

