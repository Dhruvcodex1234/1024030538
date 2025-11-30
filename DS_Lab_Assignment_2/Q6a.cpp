#include <stdio.h>

struct term {
    int r, c, v;
};

int main() {
    int n, i;

    printf("Enter number of non-zero elements: ");
    scanf("%d", &n);

    struct term a[n], t[n];

    printf("Enter triplets (row col value):\n");
    for (i = 0; i < n; i++)
        scanf("%d %d %d", &a[i].r, &a[i].c, &a[i].v);

    // transpose
    for (i = 0; i < n; i++) {
        t[i].r = a[i].c;
        t[i].c = a[i].r;
        t[i].v = a[i].v;
    }

    printf("\nTranspose:\n");
    for (i = 0; i < n; i++)
        printf("%d %d %d\n", t[i].r, t[i].c, t[i].v);

    return 0;
}

