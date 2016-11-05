#include<iostream>
using namespace std;

void sort(int f[],int m,int n)
{
    int t;
    int x,l1=m,l2=n;
    x=f[(l1+l2)/2];
    do
    {
        while (f[l1]<x) l1++;
        while (f[l2]>x) l2--;
        if (l1<=l2)
        {
            t=f[l1]; f[l1]=f[l2]; f[l2]=t;
            l1++; l2--;
        }

    }while(l1<=l2);
    if (l1<n) sort(f,l1,n);
    if (l2>m) sort(f,m,l2);
}

int gets(int f[],int &l1,int &r1,int &l2,int &r2)
{
    if (l1>r1)
    {
        int t=l2; l2++; return f[t];
    }
    if (l2>r2)
    {
        int t=l1; l1++; return f[t];
    }
    if (f[l1]<f[l2])
    {
        int t=l1; l1++; return f[t];
    }
    else
    {
        int t=l2; l2++; return f[t];
    }
}
int main()
{
    int n;
    int f[100000];
    while (cin>>n)
    {
        int p;
        for (int i=1; i<=2*n; i++)
            f[i]=0;
        for (int i=1; i<=n; i++)
        {
            cin>>f[i]>>p;
        }
        sort(f,1,n);
        int l1=1,r1=n,l2=n+1,r2=n;
        while (r1-l1+1+r2-l2+1>=2)
        {
            int min1,min2;
            min1=gets(f,l1,r1,l2,r2);
            min2=gets(f,l1,r1,l2,r2);
            r2++; f[r2]=min1+min2;
        }
        int ans=0;
        for (int i=1; i<r2; i++)
            ans+=f[i];
        cout<<ans<<endl;
    }
    return 0;
}
