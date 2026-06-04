#include <stdio.h>

#define ROWS 25
#define COLS 50

char canvas[ROWS][COLS];

void initializeCanvas() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            canvas[i][j] = '_';
        }
    }
}

void drawCircle(int centerX, int centerY, int radius) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int dx = i - centerX;
            int dy = j - centerY;

            int d = dx * dx + dy * dy;

            if(d >= radius * radius - radius &&
               d <= radius * radius + radius) {
                canvas[i][j] = '*';
            }
        }
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

    drawCircle(12, 25, 8);

    displayCanvas();

    return 0;
}
