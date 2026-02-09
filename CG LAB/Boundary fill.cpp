#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void boundaryfill(int x,int y,int f_color,int b_color)
{
    if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
    {
        putpixel(x,y,f_color);
        boundaryfill(x+1,y,f_color,b_color);
        boundaryfill(x,y+1,f_color,b_color);
        boundaryfill(x-1,y,f_color,b_color);
        boundaryfill(x,y-1,f_color,b_color);
    }
}
//getpixel(x,y) gives the color of specified pixel

int main()
{
    int gm,gd=DETECT,radius;
    int x,y;
    cout<<"Enter x and y positions for circle :";
    cin>>x>>y;
    cout<<"Enter radius of circle :";
    cin>>radius;
    initwindow(600, 500, "C201242");
    circle(x,y,radius);
    boundaryfill(x,y,0,15);
    delay(5000);
    getch();
    closegraph();
    return 0;
}
