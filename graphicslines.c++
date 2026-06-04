#include <iostream>
using namespace std;

const int ROWS = 30;
const int COLS = 60;

char canvas[ROWS][COLS];

void clearCanvas() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            canvas[i][j] = ' ';
        }
    }
}

void displayCanvas() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
}

void drawLine(int row, int col, int length) {
    for(int i = 0; i < length && col + i < COLS; i++) {
        canvas[row][col + i] = '-';
    }
}

void drawRectangle(int row, int col, int height, int width) {
    for(int i = 0; i < width; i++) {
        canvas[row][col + i] = '*';
        canvas[row + height - 1][col + i] = '*';
    }

    for(int i = 0; i < height; i++) {
        canvas[row + i][col] = '*';
        canvas[row + i][col + width - 1] = '*';
    }
}

void drawTriangle(int row, int col, int height) {
    for(int i = 0; i < height; i++) {
        canvas[row + i][col] = '*';
        canvas[row + i][col + i] = '*';
    }

    for(int i = 0; i < height; i++) {
        canvas[row + height - 1][col + i] = '*';
    }
}

void drawCircle(int centerRow, int centerCol, int radius) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int dx = i - centerRow;
            int dy = j - centerCol;
            int dist = dx * dx + dy * dy;

            if(dist >= radius * radius - radius &&
               dist <= radius * radius + radius) {
                canvas[i][j] = '*';
            }
        }
    }
}

void deleteArea(int row, int col, int height, int width) {
    for(int i = row; i < row + height && i < ROWS; i++) {
        for(int j = col; j < col + width && j < COLS; j++) {
            canvas[i][j] = ' ';
        }
    }
}

int main() {
    clearCanvas();

    int choice;

    do {
        cout << "\n===== 2D Graphics Editor =====\n";
        cout << "1. Draw Line\n";
        cout << "2. Draw Rectangle\n";
        cout << "3. Draw Triangle\n";
        cout << "4. Draw Circle\n";
        cout << "5. Delete Area\n";
        cout << "6. Display Picture\n";
        cout << "7. Clear Picture\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int r,c,len;
                cout << "Row Col Length: ";
                cin >> r >> c >> len;
                drawLine(r,c,len);
                break;
            }

            case 2: {
                int r,c,h,w;
                cout << "Row Col Height Width: ";
                cin >> r >> c >> h >> w;
                drawRectangle(r,c,h,w);
                break;
            }

            case 3: {
                int r,c,h;
                cout << "Row Col Height: ";
                cin >> r >> c >> h;
                drawTriangle(r,c,h);
                break;
            }

            case 4: {
                int r,c,rad;
                cout << "CenterRow CenterCol Radius: ";
                cin >> r >> c >> rad;
                drawCircle(r,c,rad);
                break;
            }

            case 5: {
                int r,c,h,w;
                cout << "Row Col Height Width: ";
                cin >> r >> c >> h >> w;
                deleteArea(r,c,h,w);
                break;
            }

            case 6:
                displayCanvas();
                break;

            case 7:
                clearCanvas();
                break;
        }

    } while(choice != 0);

    return 0;
}
