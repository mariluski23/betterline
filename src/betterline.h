#ifndef BETTERLINE_H
#define BETTERLINE_H

#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

#endif

int current_ln = 0;

// Wrapper function for endwin
void cleanup_ncurses() {
    endwin(); // Call endwin when exiting the program
}

void setup(char *prompt) {
    /* Initialize ncurses */
    initscr();
    if (atexit(cleanup_ncurses) != 0) { // Register cleanup function
        fprintf(stderr, "BetterLine Error: Failed to set exit handler\n");
        exit(1);
    }

    // Little checks
    if (!has_colors()) {
        fprintf(stderr, "BetterLine Error: Terminal does not support colors\n");
        exit(1);
    } else if (!can_change_color()) {
        fprintf(stderr, "BetterLine Error: Terminal does not support color changes\n");
        exit(1);
    }

    // Draw the prompt
    mvprintw(current_ln, 0, "%s", prompt);
    refresh(); // Refresh to display the changes
}

char *del_ch(int idx, char *str) {
    int len = strlen(str);
    if (idx < 0 || idx >= len) {
        return str; // If the index is out of bounds, just return the string
    }

    // Shift characters after idx to the left to delete the character at idx
    for (int i = idx; i < len; i++) {
        str[i] = str[i + 1];
    }

    return str; // Return the modified string
}
