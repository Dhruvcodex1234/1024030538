#include <stdio.h>

int isVowel(char c) {
    char x = c | 32;
    return (x=='a'||x=='e'||x=='i'||x=='o'||x=='u');
}

int main() {
    char s[100], res[100];
    int i, j = 0;

    printf("Enter string: ");
    gets(s);

    for (i = 0; s[i] != '\0'; i++) {
        if (!isVowel(s[i]))
            res[j++] = s[i];
    }
    res[j] = '\0';

    printf("Without vowels: %s", res);
    return 0;
}

