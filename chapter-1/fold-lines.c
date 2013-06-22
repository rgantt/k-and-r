#include <stdio.h>

/**
 * 1-22
 *
 * Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before
 * the n-th column of input. Make sure your program does something
 * intelligent with very long lines, and if there are no blanks
 * or tabs before the specified column.
 */
 
#define LINE_LENGTH 80
 
void print_and_clear_buffer(char[], int);
 
main() {
    int c, i, position = 0, relative_position = 0, break_position = 0;
    char line[LINE_LENGTH];
    
    while ((c = getchar()) != EOF) {
        relative_position = (position % LINE_LENGTH);        
        line[relative_position] = c;
        
        if (LINE_LENGTH == relative_position + 1) {
            for (i = relative_position; i > 0; i--) {
                if (' ' != line[i]) {
                    break_position = i + 1;
                    break;
                }
            }
            print_and_clear_buffer(line, break_position);
        }

        position++;
    }
    
    // print the remainder, which is less than one column wide
    print_and_clear_buffer(line, relative_position);
}

void print_and_clear_buffer(char buf[], int end) {
    int i;
    for (i = 0; i < end; i++) {
        printf("%c", buf[i]);
        buf[i] = 0;   
    }
    printf("\n");
}
