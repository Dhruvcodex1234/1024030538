#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[50];

    printf("Enter first string: ");
    gets(a);
    printf("Enter second string: ");
    gets(b);

    strcat(a, b);

    printf("Concatenated string: %s", a);
    return 0;
}

