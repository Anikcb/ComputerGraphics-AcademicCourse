#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;


void plotpoints(int xcenter, int ycenter, int x, int y,int color)
{

    putpixel(xcenter+x, ycenter+y,color);
    putpixel(xcenter-x, ycenter+y,color);
    putpixel(xcenter+x, ycenter-y,color);
    putpixel(xcenter-x, ycenter-y,color);
    putpixel(xcenter+y, ycenter+x,color);
    putpixel(xcenter-y, ycenter+x,color);
    putpixel(xcenter+y, ycenter-x,color);
    putpixel(xcenter-y, ycenter-x,color);
}

void Circle(int xcenter, int ycenter, int r,int color)
{
    int x = 0, y = r;
    plotpoints(xcenter,ycenter,x,y,color);
    int p = 1 - r;
    while (x<y)
    {
        x++;
        if (p<0)
            p += 2*x + 3;
        else
        {
            y--;
            p += 2*(x-y) + 5;
        }
        plotpoints(xcenter,ycenter,x,y,color);
    }
}

int main()
{
    int gm,gd=DETECT;
    initgraph(&gd,&gm,"");
    while(1){
        for(int j=1; j<=10; j++)
        {
            for(int i=60; i>=1; i--)
            {
                Circle(200,200,i,j);
            }
            for(int i=60; i>=1; i--)
            {
                Circle(230,180,i,0);
            }
            _sleep(400);
        }
    }

    getch();
    closegraph();

}
