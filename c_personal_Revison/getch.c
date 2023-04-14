#include <stdio.h>

int main(void) {
    int c;

    // read a character from stdin
    c = getchar();

    // push the character back onto stdin
    ungetc(c, stdin);

    // read the character again
    c = getchar();

    // print the character
    printf("%c\n", c);

    return 0;
}
