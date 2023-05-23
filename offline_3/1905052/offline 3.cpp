#include<iostream>
#include<cstring>
using namespace std;

class Vector
{
    char *name;
    int x,y,z;
public:
    Vector(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=0;
        y=0;
        z=0;
    }
    Vector(char *n, int a, int b, int c)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=a;
        y=b;
        z=c;
    }
    Vector(const Vector &v)
    {
        int l = strlen(v.name);
        name = new char[l+1];
        strcpy(name,v.name);
        x=v.x;
        y=v.y;
        z=v.z;
    }
    int setX(int a)
    {
        x=a;
    }
    int setY(int b)
    {
        y=b;
    }
    int setZ(int c)
    {
        z=c;
    }

    void setName(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
    }

    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int getZ()
    {
        return z;
    }

    char *getName()
    {
        return name;
    }

    ~Vector()
    {
        delete []name;
    }
    void print()
    {
        cout<<name<<":"<<" "<<x<<"x";
        if(y>0)
        {
            cout<<"+"<<y<<"y";
        }
        else
        {
            cout<<"-"<<(-1)*y<<"y";
        }
        if(z>0)
        {
            cout<<"+"<<z<<"z";
        }
        else
        {
            cout<<"-"<<(-1)*z<<"z";
        }
        cout<<endl;
    }
    Vector operator^(Vector v)
    {
        Vector temp("Result1");
        temp.x=(y*v.z)-(z*v.y);
        temp.y=(z*v.x)-(x*v.z);
        temp.z=(x*v.y)-(y*v.x);
        return temp;
    }
    bool operator==(Vector v)
    {
        if(x==v.x&&y==v.y&&z==v.z)
            return true;
        else
            return false;
    }
    Vector operator*(int i)
    {
        Vector tmp(name);
        tmp.x=x*i;
        tmp.y=y*i;
        tmp.z=z*i;
        return tmp;
    }
    Vector operator*(Vector v)
    {
        Vector tmp("Result1");
        tmp.x=x*v.x;
        tmp.y=y*v.y;
        tmp.z=z*v.z;
        return tmp;
    }
    friend Vector operator*(int i,Vector v);
};
    Vector operator*(int i,Vector v)
    {
        Vector tmp(v.name);
        tmp.x=i*v.x;
        tmp.y=i*v.y;
        tmp.z=i*v.z;
        return tmp;
    }
int main()
{
    Vector v1("v1", 1,2,3), v2("v2", 4, 5, -6), v3("Result1"),v4("Result2",-27,18,-3);

    v1.print();     ///Print the components of vector v1
    v2.print();     ///Print the components of vector v2

    v3=v1^v2;       ///Calculate the cross product of vector v1 and vector v2 (Consider ^ as cross product for this assignment)
    v3.print();     ///Print the modified components of vector v3 (Name: Result1)

   if(v3==v4)      ///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    v1= v1*2;       ///Multiply each component of vector v1 with the given value
    v1.print();     ///Print the modified components of vector v1

    v2=2*v2;        ///Multiply each component of vector v2 with the given value
    v2.print();     ///Print the modified components of vector v2

    v3=v1*v2;       ///Multiply each component of vector v1 with the corresponding component of vector v2.
    v3.print();     ///Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      ///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    return 0;
}


