#include<cstdio>

int n;
long long c;
int ans;
long long  b[4]={2,3,7,11};

long long modular(long long a,long long b,long long n)
{
    long long d=1;
    int tt[40],k=0;
    while (b>0)
    {
        tt[k]=b%2;
        b/=2;
        k++;
    }
    for (int i=k-1; i>=0; i--)
    {
        d=(d*d)%n;
        if (tt[i]==1)
        d=(d*a)%n;
    }
    return d;
}
bool witness(long long a,long long n)
{
    long long u=n-1;
    int t=0;
    while (u%2==0)
    {
        t++; u/=2;
    }
    long long x0=modular(a,u,n),x1;
    for (int i=1; i<=t; i++)
    {
        x1=(x0*x0)%n;
        if (x1==1&&x0!=1&&x0!=n-1)
        return true;
        x0=x1;
    }
    if (x0!=1)
    return true;
    return false;
}
void miller_rabin(long long n,int s)
{
    for (int j=0; j<s; j++)
    {
        if (b[j]<=n-1)
        if (witness(b[j],n))
        return;
    }
    ans++;
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        ans=0;
        for (int i=0; i<n; i++)
        {
            scanf("%lld",&c);
            miller_rabin(c,4);
        }
        printf("%d\n",ans);
    }
    return 0;
}
