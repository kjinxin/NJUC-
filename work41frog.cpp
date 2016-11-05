#include<cstdio>

void gcdextended(long long a,long long b,long long& d,long long& r,long long& s)
{
    if (b==0)
    {
        d=a; r=1; s=0; return;
    }
    long long r1,s1;
    gcdextended(b,a%b,d,r1,s1);
    r=s1; s=r1-a/b*s1;
    return;
}
int main()
{
    long long x,y,m,n,a,b,r,s,l,ans,d;
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    b=x-y; a=n-m; n=l;
    gcdextended(a,n,d,s,r);
    if (b%d!=0||m==n)
    printf("Impossible\n");
    else
    {
        ans=(




             (n/d)+n/d)%(n/d);
        printf("%lld\n",ans);
    }
    return 0;
}
