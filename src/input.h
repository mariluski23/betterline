#ifndef INPUT_H
#define INPUT_H

#include <ncurses.h>

#endif

int get_input() {
    // Get everything typed 'till enter is pressed
    int c = getch();
    while (c != 10) {
        c = getch();
    }
    printw("%c", c);
    return c;
}
