#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;

void setPixel(int x, int y, int h, int k)
{
    putpixel(x+h, y+k, WHITE);
    putpixel(x+h, -y+k, RED);
    putpixel(-x+h, -y+k, WHITE);
    putpixel(-x+h, y+k, RED);
    putpixel(y+h, x+k, WHITE);
    putpixel(y+h, -x+k, RED);
    putpixel(-y+h, -x+k, WHITE);
    putpixel(-y+h, x+k, RED);
}
main()
{
    int gd=0, gm,h,k,r;
    double x,y,xend;
    cin>>h>>k>>r;
    initwindow(600, 500, "C201242");
    x=0,y=r;
    xend = r/sqrt(2);
    while(x<=xend)
    {
        y = sqrt(r*r - x*x);
        setPixel(floor(x), floor(y), h,k);
        x++;
    }
    getch();
}
