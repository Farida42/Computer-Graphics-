#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
int main()
{
    int gd = DETECT, gm, s;
    initwindow(700, 700, "C201242");
    cout << "The basic transformation\n1.Translation\n2.Rotation\n3.Scaling\n"
         << endl;
    cout << "Enter selection: ";
    cin >> s;
    switch (s)
    {
    case 1:
    {
        int x1, y1, x2, y2;
        int tx, ty;
        cout << "Enter the starting and ending point: ";
        cin >> x1 >> y1 >> x2 >> y2;
        delay(10);
        cout << "Rectangle before translation" << endl;
        setcolor(3);
        rectangle(x1, y1, x2, y2);
        cout << "Enter translation distance: ";
        cin >> tx >> ty;
        setcolor(4);
        cout << "Rectangle after translation" << endl;
        rectangle(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
        getch();
        break;
    }
    case 2:
    {
        int x1, y1, radius;
        double s, c, angle;
        setcolor(RED);
        cout << "Enter coordinates of circle: ";
        cin >> x1 >> y1;
        cout << "Enter radius of circle: ";
        cin >> radius;
        cout << "Circle before rotation" << endl;
        circle(x1, y1, radius);
        cout << "Enter rotation angle: ";
        cin >> angle;
        c = cos(angle * 3.1416 / 180);
        s = sin(angle * 3.1416 / 180);
        x1 = x1 * c - y1 * s;
        y1 = -x1 * s + y1 * c;
        setcolor(4);
        circle(x1, y1, radius);
        getch();
        break;
    }

    case 3:
    {
        int x1, y1, x2, y2; // 30 30 70 70
        int Sy, Sx;
        cout << "Enter the starting and ending point: ";
        cin >> x1 >> y1 >> x2 >> y2;
        cout << "Before scaling" << endl;
        setcolor(1);
        rectangle(x1, y1, x2, y2);
        delay(5);
        cout << "Scaling factor: ";
        cin >> Sx >> Sy;
        cout << "After scaling" << endl;
        setcolor(10);
        rectangle(x1 * Sx, y1 * Sy, x2 * Sx, y2 * Sy);
        getch();
        break;
    }
    }
    getch();
}
