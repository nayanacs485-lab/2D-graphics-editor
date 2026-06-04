#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            canvas[i][j] = '_';
        }
    }
}

void drawTriangle(int startRow, int startCol, int height) {
    for(int i = 0; i < height; i++) {

        /* Left side */
        canvas[startRow + i][startCol] = '*';

        /* Right side */
        canvas[startRow + i][startCol + i] = '*';
    }

    /* Base */
    for(int j = 0; j < height; j++) {
        canvas[startRow + height - 1][startCol + j] = '*';
    }
}

void displayCanvas() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initializeCanvas();

    drawTriangle(3, 10, 8);

    displayCanvas();

    return 0;
}
