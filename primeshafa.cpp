#include<cstdio>
#include<cstring>
const int max=333;
int main()
{
    bool f[max];
    memset(f,0,sizeof(f));
    int n;
    scanf("%d",&n);
    int t=2,j;
    while (t<=n)
    {
        if (f[t]==1) {t++; continue;}
        j=2*t;
        while (j<=n)
        {
            f[j]=1;
            j+=t;
        }
        t++;
    }
    for (int i=2; i<=n; i++)
    if (f[i]==0)
    {
        printf("%d\n",i);
    }
    return 0;
}
