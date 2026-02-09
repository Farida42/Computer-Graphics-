#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
    int gm,gd=DETECT;
    initwindow(600, 500, "C201242");
    int x, y, xc, yc, r, d;
    cout << "Enter the center of circle : ";
    cin >> xc >> yc;
    cout << "Enter the radius of circle : ";
    cin >> r;
    d = 1 - r;
    x = 0;
    y = r;
    while(x<=y)
    {
        putpixel(xc+x, yc+y, RED);
        putpixel(xc+x, yc-y, GREEN);
        putpixel(xc-x, yc+y, GREEN);
        putpixel(xc-x, yc-y, RED);
        putpixel(xc+y, yc+x, BLUE);
        putpixel(xc+y, yc-x, WHITE);
        putpixel(xc-y, yc+x, WHITE);
        putpixel(xc-y, yc-x, BLUE);

        if(d<=0)
        {
            x++;
            d += 2 * x + 3;
        }
        else
        {
            x++;
            y--;
            d += 2 * (x - y) + 5;
        }
    }
    delay(1000);
    closegraph(); // Close graphics mode
    getch();
}

