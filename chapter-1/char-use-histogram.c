#include <stdio.h>

void horizontal_histogram( int[] );
void vertical_histogram( int[] );

#define CHARS 256

/**
 * Write a program to print a histogram of the frequencies of different characters in its input
 *
 * TODO: prune out the unused characters--use a dynamic array? must be a cleverer way
 *
 * KandR 1-14
 */

int main( int argc, char *argv[] ) {
    int i, c, frequencies[CHARS];
    
    /**
     * zero out the frequency table
     */
    for( i = 0; i < CHARS; i++ ) {
        frequencies[i] = 0;
    }

    /**
     * populate the frequency table
     */
    while( ( c = getchar() ) != EOF ) {
        frequencies[c]++;
    }
    
    for( i = 0; i < CHARS; i++ ) {
        printf("frequencies[%d] == %d\n", i, frequencies[i]);
    }
    
    horizontal_histogram( frequencies );
    vertical_histogram( frequencies );

    return 0;
}

void horizontal_histogram( int frequencies[] ) {
    int i, j;
    printf("Distribution of characters:\n");
    for( i = 0; i < CHARS; i++ ) {
        printf("%d", i);
        for( j = 0; j < frequencies[i]; j++ ) {
            printf("X");
        }
        printf("\n");
    }
}

void vertical_histogram( int frequencies[] ) {
    int i, j, max = 0;
    for( i = 0; i < CHARS; i++ ) {
        if( frequencies[i] > max ) {
            max = frequencies[i];
        }
    }
    printf("Distribution of characters:\n");
    for( i = max; i >= 0; i-- ) {
        for( j = 0; j < CHARS; j++ ) {
            if( frequencies[j] >= i && i != 0 ) {
                printf("X");
            } else if( i == 0 ) {
                printf("%d", j);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
