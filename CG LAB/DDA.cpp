#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    float x, y, x1, y1, x2, y2, dx, dy, m, steps;
    int i, gd = DETECT, gm;
    initwindow(700, 700, "C201242");
   //setbkcolor(WHITE);
    cout << "Enter the value of x1 and y1 : ";
    cin >> x1 >> y1;
    cout << "Enter the value of x2 and y2: ";
    cin >> x2 >> y2;
    dx = (x2 - x1);
    dy = (y2 - y1);
    m = dy/dx;
    cout << "m = " << m << endl;
    x = x1;
    y = y1;
    for (i = 0; i <= x2; i++)
    {
        if (m<1)
        {
            putpixel(x, y, 15);
            x = x + 1;
            y = y + m;
            delay(100);
        }
        else if(m>1)
        {
            putpixel(x, y, 4);
            x = x + (1/m);
            y = y + 1;
            delay(100);
        }
        else 
        {
            putpixel(x, y, 3);
            x = x + 1;
            y = y + 1;
            delay(100);
        }
    }
    getch();
}