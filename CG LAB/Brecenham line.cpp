#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
    int gm,gd=DETECT;
    initwindow(600, 500, "C201242");
    int x1,x2,y1,y2,p,dx,dy;
    cout<<"Enter coordinates of starting point: ";
    cin>>x1>>y1;
    cout<<"Enter coordinates of Ending point: ";
    cin>>x2>>y2;
    dx = x2-x1;
    dy = y2-y1;
    p = 2*dy-dx;
    while(x1<x2)
    {
        if(p>=0)
        {
            putpixel(x1,y1,RED);
            x1 += 1;
            y1 += 1;
            p = p+2*dy-2*dx;
        }
        else
        {
            putpixel(x1,y1,GREEN);
            x1 += 1;
            p = p+2*dy;
        }
    }

    delay(500000);
    getch();
}

