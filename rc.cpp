#include<iostream>
#include<cmath>
using namespace std;


class rat
{
    public:
        void input(int a1,int b1,int a2,int b2);
        void plus();
        void minus();
        void mul();
        void div();
        void com();
        int gcd(int x,int y);
        void output(int x,int y);
    private:
    int x1,y1,x2,y2,x,y;
    bool o;
};
int main()
{
    int x1,y1,x2,y2;
    while (cin>>x1>>y1>>x2>>y2)
    {
        rat r;
        r.input(x1,y1,x2,y2);
        r.plus();
        r.minus();
        r.mul();
        r.div();
        r.com();
    }
    return 0;
}

void rat::input(int a1,int b1,int a2,int b2)
{
    x1=a1; y1=b1; x2=a2; y2=b2;
    int y=y1*y2;
    int x=x1*y2-x2*y1;
    if (((x<0)&&(y>0))||((x>0)&&(y<0)))
    o=true;
    else o=false;
}

int rat::gcd(int x,int y)
{
    if (x % y==0) return y;
    else return gcd(y,x % y);
}

void rat::plus()
{
    int x=x1*y2+x2*y1;
    int y=y1*y2;
    output(x,y);
}

void rat::minus()
{
    int y=y1*y2;
    int x=x1*y2-x2*y1;
    output(x,y);
}

void rat::mul()
{
    int x=x1*x2;
    int y=y1*y2;
    output(x,y);
}

void rat::div()
{
    int x=x1*y2;
    int y=y1*x2;
    output(x,y);
}

void rat::com()
{
    if (o) cout<<"true"; else cout<<"false";
    cout<<endl;
}
void rat::output(int x,int y)
{
    if (((x<0)&&(y>0))||((x>0)&&(y<0))) cout<<'-';
    if (x<0) x=-x;
    if (y<0) y=-y;
    int z=gcd(x,y);
    if (y/z>1) cout<<x/z<<'/'<<y/z;
    else cout<<x/z;
    cout<<' ';
}
