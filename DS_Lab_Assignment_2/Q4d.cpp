#include <stdio.h>
#include <string.h>

int main() {
    char s[10][50];
    int n, i, j;
    char temp[50];

    printf("Enter number of strings: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%s", s[i]);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(s[i], s[j]) > 0) {
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }

    printf("Sorted strings:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", s[i]);

    return 0;
}

