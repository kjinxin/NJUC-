#include<iostream>
#include<cstdio>
using namespace std;

int f[5010],g[5010],n,a[5010],ans1=0,ans2=0;
int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    f[1]=1; g[n]=1;
    for (int i=2; i<=n; i++)
    {
        f[i]=1;
        for (int j=1; j<i; j++)
        if ((a[i]>a[j])&&(f[j]+1>f[i]))
        {
            f[i]=f[j]+1;
        }
        if (f[i]>ans1)
        ans1=f[i];
    }
    for (int i=n-1; i>=1; i--)
    {
        g[i]=1;
        for (int j=n; j>i; j--)
        if (a[i]>a[j]&&g[j]+1>g[i])
        {
            g[i]=g[j]+1;
        }
    }
    for (int i=1; i<=n; i++)
    if (f[i]+g[i]-1>ans2)
    ans2=f[i]+g[i]-1;
    printf("%d %d\n",ans1,ans2);
    return 0;
}
