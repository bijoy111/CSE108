#include <iostream>
#include<math.h>
using namespace std;
class Point
{
// x and y coordinate
    int x, y;
public:
//Add necessary constructor(s) to initialize x and y
//Add your set and get functions for x and y
    Point() {}
    Point(int a,int b)
    {
        x=a;
        y=b;
    }
    void set(int a,int b)
    {
        x=a;
        y=b;
    }
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    void print()
    {
        cout << "Coordinate: "<< x <<", " <<y <<endl;
    }
    void print(int a,int b)
    {
        cout << "Coordinate: "<<a <<", " <<b <<endl;
    }
};
class Circle
{
    Point p;
    int radius;
    int x,y;
public:
// Add necessary constructor(s) to initialize p and radius
// Overload “upload” functions
    Circle(int a,int b,int c)
    {
        x=a;
        y=b;
        radius=c;
    }
    void print()
    {
        cout << "Center ";
        p.print(x,y);
        cout << "Radius: " << radius << endl;
    }
    void update(int a,int b)
    {
        x+=a;
        y+=b;
    }
    void update(int c)
    {
        radius+=c;
    }
    void update(int a,int b,int c)
    {
        x+=a;
        y+=b;
        radius+=c;
    }
};
class Line
{
    Point p1;
    Point p2;
    int x1,y1,x2,y2;
public:
    Line(int a1,int b1,int a2,int b2)
    {
        p1.set(a1,b1);
        p2.set(a2,b2);
    }
    void print()
    {
        x1=p1.getx();
        x2=p2.getx();
        y1=p1.gety();
        y2=p2.gety();
        cout<<sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    }
};
int main()
{
    Point p(5,5);
    Circle c(2, 3, 5);
    cout << endl << "Point Display" <<endl;
    p.print();
    cout << endl << "Circle Display" <<endl;
    c.print();
    cout << endl;


//First update
    cout << "First Update" << endl;
// call “update” function of Circle class to increase the center’s x
//coordinate by 5 and y coordinate by 5;
    c.update(5,5);
    c.print();
    cout <<endl;

//Second update
    cout << "Second Update" << endl;

// call “update” function of Circle class to increase the radius by 6;
    c.update(6);
    c.print();
    cout << endl;

//Third update
    cout << "Third Update" << endl;

// call “update” function of Circle class to increase the center’s x
//coordinate by 2 and y coordinate by 2 and the radius by 2;
    c.update(2,2,2);
    c.print();
    cout << endl;
    cout<<endl;
    cout<<"Give coordinate of two point those make a line to find the length of that line:"<<endl;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    Line object(x1,y1,x2,y2);
    cout<<"The length of the line is:  ";
    object.print();
    return 0;
}
