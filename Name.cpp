
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
    while(1)
    {
        for(int i=1; i<=10; i++)
        {
            line(150,150,200,380);
            line(153,120,203,383);

            line(150,150,100,380);
            line(153,120,97,380);

            line(122,280,177,280);
            line(121,283,179,283);

            for(int j=60; j>=1; j--)
            {
                Circle(300,200,j,i);
                Circle(300,320,j,i);
            }
            _sleep(50);

        }
    }

    getch();
    closegraph();

}
