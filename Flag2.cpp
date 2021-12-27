
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void Line(float x1, float y1, float x2, float y2,float color)
{
    if(x1==x2)
    {
        for(int  i=y1;i<=y2;i++)putpixel(x1,i,color);
        return;
    }

    float dx = abs(x1-x2),dy = abs(y1-y2);
    float d = (2*dy)-dx;
    while(x1<x2)
    {
        putpixel(x1,y1,color);
        if(d<0)d+=(2*dy);
        else
        {
            y1++;
            d+=(2*(dy-dx));
        }
        x1++;
    }
}

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
    for(int i=1;i<=10;i++)
    {
        for(int j=200;j<=400;j++)
        {
            Line(100,j,500,j,((10-i==5||10-i==0)?10-i+1:10-i));
        }
        for(int j=60;j>=1;j--)
        {
            Circle(300,300,j,i);
        }
        _sleep(500);
        cleardevice();
        _sleep(100);
    }
    }
    getch();
    closegraph();

}
