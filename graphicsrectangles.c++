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

void drawRectangle(int row, int col, int height, int width) {

    /* Top and Bottom */
    for(int j = 0; j < width; j++) {
        canvas[row][col + j] = '*';
        canvas[row + height - 1][col + j] = '*';
    }

    /* Left and Right */
    for(int i = 0; i < height; i++) {
        canvas[row + i][col] = '*';
        canvas[row + i][col + width - 1] = '*';
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

    drawRectangle(4, 8, 8, 15);

    displayCanvas();

    return 0;
}
