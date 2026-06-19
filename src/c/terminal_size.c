#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

void get_terminal_size(int *rows, int *cols) {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
      
        *rows = 24;
        *cols = 80;
    } else {
        *rows = w.ws_row;
        *cols = w.ws_col;
    }
}

int main() {
    int rows, cols;
    get_terminal_size(&rows, &cols);
    printf("Terminal atual: %d linhas x %d colunas\n", rows, cols);
    return 0;
}
