#include<iostream>
#include<cstring>
using namespace std;

double justdo(double a[],int s,int n,int num)
{
    double p=0;
    if (num==1)
    {
        for (int i=s; i<n; i++)
        p+=a[i];
        return p;
    }
    for (int i=s; i<n-num+1; i++)
    {
        p+=a[i]*justdo(a,i+1,n,num-1);
    }
    return p;
}
int main()
{
    int t,n;
    double a[20];
    double p=0;
    cin>>t;
    for (int q=0; q<t; q++)
    {
        memset(a,0,sizeof(a));
        cin>>n;
        p=0;
        for (int i=0; i<n; i++)
        {
            cin>>a[i];
            a[i]=1.0/a[i];
        }
        for (int i=1; i<=n; i++)
        {
            if (i%2==0)
            {
                p-=justdo(a,0,n,i);
            }
            else
            {
                p+=justdo(a,0,n,i);
            }
        }
        cout<<365.0*(1.0-p)<<' '<<365.0*p*(1.0-p);
        if (p!=t-1) cout<<endl;
    }
    return 0;
}
