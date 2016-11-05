#include<iostream>
using namespace std;

void swap(long long &a,long long &b)
{
    long long t;
    if (a>b)
    {
        t=a; a=b; b=t;
    }
    return ;
}

long long beishu(long long a,long long b)
{
    long long t=b;
    while (t%a!=0)
    t+=b;
    return t;
}
int main()
{
    int t;
    cin>>t;
    for (int p=1; p<=t; p++)
    {
        long long n,a,b;
        cin>>n>>a>>b;
        swap(a,b);
        long long c=beishu(a,b);
        long long ans=0,mans=0;
        long long q=n%c;
        bool o=true;
        for(int i=1; i<c/a; i++)
        {
            long long k=(a*i)%b;
            if ((o)&&(a*(i+1)>q))
            {
                o=false;
                mans=ans;
            }
            if (b-k>=a)
            ans+=k*a;
            else
            {
                ans+=k*(b-k)+(a-b+k)*(b-k);
            }
        }
        long long fans=n/c*ans+mans;
        long long k=(q/a*a)%b;
        long long yu=q%a;
        if (b-k>=yu)
        fans+=k*yu;
        else
        {
            fans+=k*(b-k)+(yu-b+k)*(b-k);
        }
        cout<<fans<<endl;
    }
    return 0;
}
