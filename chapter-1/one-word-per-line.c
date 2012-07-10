#include <stdio.h>

#define WORD 0
#define WHITESPACE 1

/**
 * Write a program that prints its input one word per line
 *
 * KandR 1-12
 */
int main( int argc, char *argv[] ) {
    int c, state = WHITESPACE;
    while( ( c = getchar() ) != EOF ) {
        if( ( c == ' ' || c == '\t' ) ) {
            if( state == WORD ) {
                state = WHITESPACE;
                printf("\n");
            }
        } else {
            state = WORD;
            printf("%c", c);
        }
    }
    return 0;
}
