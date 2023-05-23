#include<iostream>
using namespace std;

class Vectors
{
    int **a;
    int n;

public:
    Vectors(int num)
    {
        n = num;
        a = (int**) malloc(n*sizeof(int*));
        for(int i=0; i<n; i++)
            *(a+i) = (int*) malloc(3*sizeof(int));
    }

    Vectors()
    {
        for(int i=0; i<n; i++)
            free(*(a+i));
        free(a);
    }

    void print()
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<3; j++)
                cout<<*(*(a+i)+j)<<' ';
            cout<<endl;
        }
    }

    void setVector(int index, int x, int y, int z)
    {
        if(index>=n)
        {
            cout<<"invalid index"<<endl;
            return;
        }
        *(*(a+index)+0) = x;
        *(*(a+index)+1) = y;
        *(*(a+index)+2) = z;
    }

    void add(int x, int y, int z)
    {
        for(int i=0; i<n; i++)
        {
            *(*(a+i)+0) += x;
            *(*(a+i)+1) += y;
            *(*(a+i)+2) += z;
        }
    }

    int* add()
    {
        int x=0, y=0, z=0;
        for(int i=0; i<n; i++)
        {
            x += *(*(a+i)+0);
            y += *(*(a+i)+1);
            z += *(*(a+i)+2);
        }

        int p[3] = {x, y, z};
        return p;
    }
};

int main()
{
    return 0;
}

