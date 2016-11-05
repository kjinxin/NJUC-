#include<cstdio>

int f[5004][5004],a[5010];
int main()
{
    int t;
    scanf("%d",&t);
    for (int p=1; p<=t; p++)
    {
        int n;
        scanf("%d",&n);
        for (int i=1; i<=n; i++)
        scanf("%d",&a[i]);
        int x,y,z;
        for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        f[i][j]=0;
        for (int l=2; l<=n; l++)
        {
            for (int i=1; i<=n-l+1; i++)
            {
                int j=i+l-1;
                x=a[i]; y=a[j];
                while (x%y!=0)
                {
                    z=x%y;
                    x=y;
                    y=z;
                }
                f[i][j]=y;
                if (f[i][j-1]>f[i][j]) f[i][j]=f[i][j-1];
                if (f[i+1][j]>f[i][j]) f[i][j]=f[i+1][j];
            }
        }
        int q,l,r;
        scanf("%d",&q);
        for (int i=1; i<=q; i++)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",f[l][r]);
        }
    }
    return 0;
}
