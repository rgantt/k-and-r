#include <stdio.h>

// i'd like a more classy way to loosen this constraint a bit
#define MAX_WORD_LENGTH 10

#define WORD 0
#define SPACE 1

void horizontal_histogram( int[] );
void vertical_histogram( int[] );

/**
 * write a program to print a histogram of the lengths of words in its input
 *
 * KandR 1-13
 */

int main( int argc, char *argv[] ) {
    int frequencies[MAX_WORD_LENGTH], i, c, state = SPACE, current_word_length = 0;
    
    /**
     * zero out the frequency table
     */
    for( i = 0; i < MAX_WORD_LENGTH; i++ ) {
        frequencies[i] = 0;
    }

    /**
     * populate the frequency table
     */
    while( ( c = getchar() ) != EOF ) {
        if( c == ' ' || c == '\t' || c == '\n' ) {
            if( state == WORD ) {
                state = SPACE;
                frequencies[current_word_length]++;
                current_word_length = 0;
            }
        } else {
            state = WORD;
            current_word_length++;
        }
    }
    
    horizontal_histogram( frequencies );
    vertical_histogram( frequencies );

    return 0;
}

/**
 * it is easy to draw the histogram with the bars horizontal;
 */
void horizontal_histogram( int frequencies[] ) {
    int i, j;
    printf("Distribution of word lengths:\n");
    for( i = 0; i < MAX_WORD_LENGTH; i++ ) {
        printf("%d", i);
        for( j = 0; j < frequencies[i]; j++ ) {
            printf("X");
        }
        printf("\n");
    }
}

/**
 * a vertical orientation is more challenging
 */
void vertical_histogram( int frequencies[] ) {
    int i, j, max = 0;
    for( i = 0; i < MAX_WORD_LENGTH; i++ ) {
        if( frequencies[i] > max ) {
            max = frequencies[i];
        }
    }
    printf("Distribution of word lengths:\n");
    for( i = max; i >= 0; i-- ) {
        for( j = 0; j < MAX_WORD_LENGTH; j++ ) {
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
