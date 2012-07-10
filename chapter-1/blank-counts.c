#include <stdio.h>

/**
 * Write a program to count blanks, tabs, and newlines
 *
 * KandR 1-8
 */
int main( int argc, char *argv[] ) {
    int c, bc = 0, tc = 0, nc = 0;
    while( ( c = getchar() ) != EOF ) {
        // dirtbag
        if( ( c == ' ' && bc++ ) || ( c == '\t' && tc++ ) || ( c == '\n' && nc++ ) );
    }
    printf( "blanks: %d, tabs: %d, newlines: %d\n", bc, tc, nc );

    return 0;
}
