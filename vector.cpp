#include<iostream>
using namespace std;

class vec
{
    public:
        void initial(int n,int m);
        void push();
        void output();
        void resize();
    private:
    int size,capacity;
    int *p;
};
int main()
{
    int m,n;
    while (cin>>n>>m)
    {
        vec v;
        if (n==0) n=1;
        v.initial(0,n);
        for (int i=1; i<=m; i++)
        {
            v.push();
        }
        v.output();
    }
    return 0;
}

void vec::output()
{
    for (int i=0; i<size-1; i++)
    cout<<p[i]<<' ';
    cout<<p[size-1]<<endl;
    cout<<size<<' '<<capacity<<endl;
}

void vec::initial(int n,int m)
{
    size=n; capacity=m;
    p=new int[m];
}

void vec::resize()
{
    capacity*=2;
    int *q;
    q=new int[capacity];
    for (int i=0; i<size; i++)
    q[i]=p[i];
    p=q;
}

void vec::push()
{
    if (size+1>capacity)
        resize();
    cin>>p[size];
    size++;
}

