#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long n,q=1,a,b,c,d,ans[1000];
    int num=0;
    cin>>n;
    int t=log(n+1)/log(2)+2;
    cout<<t<<endl;
    long long x1,x2;
    for (int i=1; i<=t; i++)
    {
        a=1; b=2*q*q-3*q; c=-2*n*q*q;
        if (b*b-4*a*c>=0)
        {
            x1=(-b-sqrt(b*b-4*a*c))/2;
            x2=(-b+sqrt(b*b-4*a*c))/2;
            cout<<x1<<' '<<x2<<endl;
            if ((x1*x1+b*x1+c==0)&&(x1%q==0)&&((x1/q)%2==1))
            {
                num++; ans[num]=x1;
            }
            if ((x2*x2+b*x2+c==0)&&(x2%q==0)&&((x2/q)%2==1))
            {
                num++; ans[num]=x2;
            }
        }
        q*=2;
    }
    if (num==0)
    cout<<-1<<endl;
    else
    {
        for (int i=1; i<num; i++)
        for (int j=i+1; j<=num; j++)
        {
            if (ans[i]>ans[j])
            {
                long long t; t=ans[i]; ans[i]=ans[j]; ans[j]=t;
            }
        }
        ans[0]=-1;
        for (int i=1; i<=num; i++)
        {
            if (ans[i]!=ans[i-1])
            cout<<ans[i]<<endl;
        }
    }
    return 0;

}
