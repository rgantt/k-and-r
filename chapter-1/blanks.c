#include <stdio.h>

#define SPACE 1
#define WORD 0

/**
 * Write a program to copy its input to its output, replacing each
 * string or one or more blanks by a single blank
 *
 * KandR problem 1-9
 */
int main( int argc, char *argv[] ) {    
    int c, state = WORD;
    while( ( c = getchar() ) != EOF ) {
        if( c == ' ' || c == '\t' ) {
            if( state != SPACE ) {
                printf(" ");
            }
            state = SPACE;
        } else {
            state = WORD;
            printf("%c", c);
        }
    }
    return 0;
}
