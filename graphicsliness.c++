#include <stdio.h>
#include <stdlib.h>

#define WIDTH 25
#define HEIGHT 15

char canvas[HEIGHT][WIDTH];

void initCanvas()
{
    for(int i=0;i<HEIGHT;i++)
        for(int j=0;j<WIDTH;j++)
            canvas[i][j]='_';
}

void putPixel(int x,int y)
{
    if(x>=0 && x<WIDTH && y>=0 && y<HEIGHT)
        canvas[y][x]='*';
}

void drawLine(int x1,int y1,int x2,int y2)
{
    int dx=x2-x1;
    int dy=y2-y1;

    int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);

    float xInc=dx/(float)steps;
    float yInc=dy/(float)steps;

    float x=x1,y=y1;

    for(int i=0;i<=steps;i++)
    {
        putPixel((int)x,(int)y);
        x+=xInc;
        y+=yInc;
    }
}

void display()
{
    for(int i=0;i<HEIGHT;i++)
    {
        for(int j=0;j<WIDTH;j++)
            printf("%c",canvas[i][j]);
        printf("\n");
    }
}

int main()
{
    initCanvas();
    drawLine(2,2,20,10);
    display();
    return 0;
}
