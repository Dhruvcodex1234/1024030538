#include <stdio.h>

int main() {
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);

    if (c >= 'A' && c <= 'Z')
        c = c + 32;

    printf("Lowercase: %c", c);
    return 0;
}

