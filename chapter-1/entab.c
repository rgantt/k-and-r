#include <stdio.h>

/**
 * 1-21
 *
 * Write a program, entab, that replaces strings of blanks by the minimum 
 * number of tabs and blanks to achieve the same spacing. Use the same tab 
 * stops as for detab. When either a tab or a single blank would suffice 
 * to reach a tab stop, which should be given preference?
 */

#define TAB_STOP_LENGTH 5

void print_tabs_and_blanks(int, int, int);

main() {
    int line_position = 0, blank_length = 0, c;
    while ((c = getchar()) != EOF) {
        line_position++;
        if (' ' == c) {
            blank_length++;
        } else {
            if (blank_length > 0) {
                print_tabs_and_blanks((line_position - blank_length), blank_length, TAB_STOP_LENGTH);
            }
            blank_length = 0;
            printf("%c", c);
        }
    }
}

void print_tabs_and_blanks(int line_position, int length, int tab_stop_length) {
    int distance_from_tab_stop = line_position % tab_stop_length, i;
    
    // use as much space with tabs as possible
    while (length > tab_stop_length) {
        if (distance_from_tab_stop <= length) {
            printf("\t");
        } else {
            break;
        }
        length = length - tab_stop_length;
    }
        
    // print the remaining length as blanks
    for (; length >= 0; length--) {
        printf(" ");
    }
}
