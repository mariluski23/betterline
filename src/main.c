#include "betterline.h"
#include <ncurses.h>
#include <unistd.h> // For getlogin() and gethostname()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h" // Ensure this defines get_input()

int main() {
    char input[100] = "hi!";
    char *user = getlogin();
    if (!user) {
        fprintf(stderr, "Error: Unable to retrieve username\n");
        exit(1);
    }

    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) != 0) {
        perror("Error: gethostname failed");
        exit(1);
    }

    char prompt[256];
    snprintf(prompt, sizeof(prompt), "%s@%s # ", user, hostname); // NOTE: Snprintf() is the actual way to format strings

    setup(prompt);
    refresh();

    // Check for Ctrl-D
    if (getch() == 4) { // ASCII value of Ctrl-D is 4
        endwin();
        exit(0);
    }

    // Check for Backspace
    if (getch() == 8 || getch() == KEY_BACKSPACE) {
        // Delete the last character
        input[strlen(input) - 1] = '\0';
        refresh();
    }

    get_input(); // Ensure this function is properly defined
    endwin();    // Clean up ncurses
    return 0;
}

