#include<iostream>
#include<cmath>
using namespace std;

struct cordinate
{
    double x,y;
};
cordinate a[100000];
int num;
double dis=0;

double jiaodujisuan(double x1,double y1,double x2,double y2)
{
    return (x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2));
}
void yidong(int total,int v1,int v2,int v3)
{
    double dis1;
    dis1=sqrt((a[v3].x-a[v1].x)*(a[v3].x-a[v1].x)+(a[v3].y-a[v1].y)*(a[v3].y-a[v1].y));
    if (dis1>dis) dis=dis1;
    dis1=sqrt((a[v3].x-a[v2].x)*(a[v3].x-a[v2].x)+(a[v3].y-a[v2].y)*(a[v3].y-a[v2].y));
    if (dis1>dis) dis=dis1;
    if (total==num) return;
    double thta1,thta2;
    int v33;
    if (v2!=num) v33=v2+1; else v33=1;
    thta1=jiaodujisuan(a[v2].x-a[v1].x,a[v2].y-a[v1].y,a[v33].x-a[v2].x,a[v33].y-a[v2].y);
    int v32;
    if (v3!=num) v32=v3+1; else v32=1;
    thta2=jiaodujisuan(a[v1].x-a[v2].x,a[v1].y-a[v2].y,a[v32].x-a[v3].x,a[v32].y-a[v3].y);
    if (thta1>thta2) yidong(total+1,v2,v33,v3);
    else yidong(total+1,v3,v32,v2);
}
void init()
{
    cin>>num;
    for (int i=1; i<=num; i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    double dis1=0;
    int t;
    for (int i=1; i<=num; i++)
    {

        dis1=(a[i].y*(a[1].x-a[2].x)+a[i].x*(a[2].y-a[1].y)+a[1].y*a[2].x-a[1].x*a[2].y)/
                sqrt((a[1].x-a[2].x)*(a[1].x-a[2].x)+(a[1].y-a[2].y)*(a[1].y-a[2].y));
        if (dis1>dis)
        {
            dis=dis1;
            t=i;
        }

    }
    yidong(1,1,2,t);
}
int main()
{
    init();
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout<<dis<<endl;
    return 0;
}
