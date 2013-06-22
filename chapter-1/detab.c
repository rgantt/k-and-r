#include <stdio.h>

/**
 * 1-20
 *
 * Write a program, detab, that replaces tabs in the input with the 
 * proper number of blanks to space to the next tab stop. Assume a 
 * fixed set of tab stops, say every n columns. Should n be a 
 * variable or a symbolic parameter?
 */
 
#define N 4

main() {
    int c, i;
    while ((c = getchar()) != EOF) {
        if ('\t' == c) {
            for (i = 0; i < N; i++) {
                printf(" ");
            }
        } else {
            printf("%c", c);
        }
    }
}
