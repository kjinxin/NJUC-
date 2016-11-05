#include<iostream>
using namespace std;

int n;
double c,q[1000],w[1000],p[1000],tt[1000];
void qsort(int m,int n)
{
    int l1=m,l2=n;
    double x=tt[(l2+l1)/2],t;
    while (l1<=l2)
    {
        while (tt[l1]>x) l1++;
        while (tt[l2]<x) l2--;
        if (l1<=l2)
        {
            t=tt[l1]; tt[l1]=tt[l2]; tt[l2]=t;
            t=p[l1]; p[l1]=p[l2]; p[l2]=t;
            t=w[l1]; w[l1]=w[l2]; w[l2]=t;
            t=q[l1]; q[l1]=q[l2]; q[l2]=t;
            l1++; l2--;
        }
    }
    if (l1<n) qsort(l1,n);
    if (l2>m) qsort(m,l2);
}
int main()
{
    double ans=0;
    cin>>n>>c;
    for (int i=1; i<=n; i++)
    {
        cin>>q[i]>>w[i]>>p[i];
        tt[i]=p[i]/w[i];
        cout<<tt[i]<<endl;
    }
    qsort(1,n);
    for (int i=1; i<=n; i++)
    {
        if (c-q[i]*w[i]<0)
        {
            ans+=p[i]*(c/w[i]);
            cout<<c/w[i]<<' '<<p[i]*(c/w[i])<<endl;
            break;
        }
        else
        {
            ans+=p[i]*q[i];
            c-=q[i]*w[i];        }
        cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
