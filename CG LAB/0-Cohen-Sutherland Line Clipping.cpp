#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

// Define region codes
int INSIDE = 0; // 0000
int LEFT = 1;   // 0001
int RIGHT = 2;  // 0010
int BOTTOM = 4; // 0100
int TOP = 8;    // 1000

// Define the window boundaries
int X_MIN, X_MAX, Y_MIN, Y_MAX;

int main()
{
    int gd = DETECT, gm;
    initwindow(700, 700, "C201242");

    // Set the background color to white
    setbkcolor(WHITE);
    // Input window coordinates
    cout<<"\n\t\t\t****** Cohen Sutherland Line Clipping algorithm ***********";
    cout<<"\n\n Now, enter XMin, YMin : ";
    cin>>X_MIN>>Y_MIN;
    cout<<"\n First enter XMax, YMax : ";
    cin>>X_MAX>>Y_MAX;
    // Draw the window
    setcolor(WHITE);
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    // Input line coordinates
    int x1, y1, x2, y2;
    cout<<"\n Please enter initial point x1 and y1 : ";
    cin>>x1>>y1;
    cout<<"\n Now, enter final point x2 and y2 : ";
    cin>>x2>>y2;
    // Draw the original line
    setcolor(GREEN);
    line(x1, y1, x2, y2);

    int code1 = 0, code2 = 0;
    bool accept = false;

    while (true)
    {
        code1 = 0;
        code2 = 0;

        // Compute region codes for both endpoints
        if (x1 < X_MIN)
            code1 |= LEFT;
        if (x1 > X_MAX)
            code1 |= RIGHT;
        if (y1 < Y_MIN)
            code1 |= BOTTOM;
        if (y1 > Y_MAX)
            code1 |= TOP;

        if (x2 < X_MIN)
            code2 |= LEFT;
        if (x2 > X_MAX)
            code2 |= RIGHT;
        if (y2 < Y_MIN)
            code2 |= BOTTOM;
        if (y2 > Y_MAX)
            code2 |= TOP;

        if (!(code1 | code2)) // Both endpoints inside the window
        {
            accept = true;
            break;
        }
        else if (code1 & code2) // Both endpoints outside the window
        {
            break;
        }
        else
        {
            int codeOut;
            if (code1 != 0)
            {
                codeOut = code1;
            }
            else
            {
                codeOut = code2;
            }
            int x, y;
            float slope=(float)(y2-y1)/(x2-x1);
            if (codeOut & TOP)
            {
                x = x1 + (Y_MAX - y1) / slope;
                y = Y_MAX;
            }
            else if (codeOut & BOTTOM)
            {
                x = x1 +  (Y_MIN - y1) / slope;
                y = Y_MIN;
            }
            else if (codeOut & RIGHT)
            {
                y = y1 + (X_MAX - x1) * slope;
                x = X_MAX;
            }
            else
            {
                y = y1 +  (X_MIN - x1) * slope;
                x = X_MIN;
            }

            if (codeOut == code1)
            {
                x1 = x;
                y1 = y;
            }
            else
            {
                x2 = x;
                y2 = y;
            }
        }
    }

    if (accept)
    {
        delay(1000);
        clearviewport();
        setcolor(BLUE);
        rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
        setcolor(RED);
        line(x1,y1,x2,y2);
    }
    else
    {
        // Line is outside the window, do not draw it
    }

    getch();
}
