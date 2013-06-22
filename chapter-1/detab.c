#include <stdio.h>

/**
 * 1-20
 *
 * Write a program, detab, that replaces tabs in the input with the 
 * proper number of blanks to space to the next tab stop. Assume a 
 * fixed set of tab stops, say every n columns. Should n be a 
 * variable or a symbolic parameter?
 */
 
#define TAB_STOP_LENGTH 4

main() {
    int line_position = 0, distance_to_tab_stop, c;
    while ((c = getchar()) != EOF) {
        line_position++;
        if ('\t' == c) {
            distance_to_tab_stop = line_position % TAB_STOP_LENGTH;
            for (; distance_to_tab_stop >= 0; distance_to_tab_stop--) {
                printf(" ");
            }
        } else {
            printf("%c", c);
        }
    }
}
