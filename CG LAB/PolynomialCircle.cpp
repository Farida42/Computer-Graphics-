#include<graphics.h>  
#include<bits/stdc++.h>  
using namespace std; 
void setPixel(int x, int y, int h, int k)  
{  
    putpixel(x+h, y+k, RED);  
    putpixel(x+h, -y+k, RED);  
    putpixel(-x+h, -y+k, RED);  
    putpixel(-x+h, y+k, RED);  
    putpixel(y+h, x+k, RED);  
    putpixel(y+h, -x+k, RED);  
    putpixel(-y+h, -x+k, RED);  
    putpixel(-y+h, x+k, RED);  
}  
main()  
{  
    int gd=0, gm,h,k,r;  
    double x,y,x2;  
    cout << "Enter the point(h,k): ";
    cin >> h >> k; 
    cout << "Enter radius(r): "; 
    cin >>  r; 
    initwindow(800, 800, "C201242");
    x=0,y=r;  
    x2 = r/sqrt(2);  
    while(x<=x2)  
    {  
        y = sqrt(r*r - x*x);  
        setPixel(floor(x), floor(y), h,k);  
        x += 1;  
    }  
    getch();  
} 