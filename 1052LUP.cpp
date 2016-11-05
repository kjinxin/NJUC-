#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
using namespace std;

const int maxm=15;

void LUP_decomposition(double a[][maxm],int n)
{
    int pi[maxm];
    bool o=true;
    double ini=0;
    for (int i=1; i<=n; i++)
    pi[i]=i;
    double p; int k1;
    for (int k=1; k<=n; k++)
    {
        p=0;
        for (int i=k; i<=n; i++)
        if (fabs(a[i][k])>p)
        {
            p=fabs(a[i][k]);
            k1=i;
        }
        if (p<0.0000000001)
        {
            printf("singular matrix!\n");
            o=false; break;
        }
        else
        {
            int t=pi[k]; pi[k]=pi[k1]; pi[k1]=t;
            double tt;
            for (int i=1; i<=n; i++)
            {
                tt=a[k][i]; a[k][i]=a[k1][i]; a[k1][i]=tt;
            }
        }
        for (int i=k+1; i<=n; i++)
        {
            a[i][k]/=a[k][k];
            for (int j=k+1; j<=n; j++)
            a[i][j]-=a[i][k]*a[k][j];
        }
    }
    if (o)
    {
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<i; j++)
            printf("%.4f ",a[i][j]);
            if (i==n) printf("%.4f \n",1.0);
            else printf("%.4f ",1.0);
            for (int j=i+1; j<=n; j++)
            {
                if (j==n)
                printf("%.4f \n",0.0);
                else
                printf("%.4f ",0.0);
            }
        }
        printf("\n");
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<i; j++)
            printf("%.4f ",0.0);
            for (int j=i; j<=n; j++)
            {
                if (j==n)
                printf("%.4f \n",a[i][j]);
                else
                printf("%.4f ",a[i][j]);
            }
        }
        printf("\n");
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n-1; j++)
            {
                if (pi[i]==j)
                printf("1 ");
                else printf("0 ");
            }
            if (pi[i]==n)
            printf("1 \n");
            else printf("0 \n");
        }
    }
}
int main()
{
    int n;
    double a[maxm][maxm];
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        cin>>a[i][j];
    }
    LUP_decomposition(a,n);
    return 0;
}
