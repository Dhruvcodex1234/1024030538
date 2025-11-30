#include <stdio.h>
#include <string.h>

int main() {
    char s[50];
    int i, len;

    printf("Enter a string: ");
    gets(s);

    len = strlen(s);

    printf("Reversed string: ");
    for (i = len - 1; i >= 0; i--)
        printf("%c", s[i]);

    return 0;
}

