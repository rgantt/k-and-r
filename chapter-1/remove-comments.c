#include <stdio.h>

/**
 * 1-23
 *
 * Write a program to remove all comments from a C program. Don't
 * forget to handle quoted strings and character constants properly.
 * C commends do not nest.
 */
 
#define NOT_IN_COMMENT 0
#define MAYBE_ENTERING_COMMENT 1
#define IN_SHORT_COMMENT 2
#define IN_LONG_COMMENT 3
#define MAYBE_LEAVING_COMMENT 4
#define DEFINITELY_LEAVING_COMMENT 5
 
main() {
    int c, last_c, state = NOT_IN_COMMENT, last_state = NOT_IN_COMMENT;
    
    while ((c = getchar()) != EOF) {
        if ('/' == c) {
            if (NOT_IN_COMMENT == state) {
                last_state = state;
                state = MAYBE_ENTERING_COMMENT;
                last_c = c;
            } else if (MAYBE_ENTERING_COMMENT == state) {
                last_state = state;
                state = IN_SHORT_COMMENT;
            } else if (MAYBE_LEAVING_COMMENT == state) {
                last_state = state;
                state = DEFINITELY_LEAVING_COMMENT;
            } else {
                last_state = state;
                state = NOT_IN_COMMENT;
            }
        } else if ('*' == c) {
            if (MAYBE_ENTERING_COMMENT == state) {
                last_state = state;
                state = IN_LONG_COMMENT;
            } else if (IN_LONG_COMMENT == state) {
                last_state = state;
                state = MAYBE_LEAVING_COMMENT;
            }
        } else if ('\n' == c) {
            if (IN_SHORT_COMMENT == state) {
                last_state = state;
                state = DEFINITELY_LEAVING_COMMENT;
            }
        } else {
            if (MAYBE_ENTERING_COMMENT == state) {
                last_state = state;
                state = NOT_IN_COMMENT;
            } else if (MAYBE_LEAVING_COMMENT == state) {
                state = last_state;
                last_state = MAYBE_LEAVING_COMMENT;
            } else if (DEFINITELY_LEAVING_COMMENT == state) {
                last_state = state;
                state = NOT_IN_COMMENT;
            } else {
                last_state = state;
            }
        }
        
        if (NOT_IN_COMMENT == state) {
            if (MAYBE_ENTERING_COMMENT == last_state) {
                printf("%c", last_c);
            }
            printf("%c", c);
        }
    }
}
