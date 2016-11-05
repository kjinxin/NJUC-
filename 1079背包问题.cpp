#include<cstdio>

int w[100],c[100];
double v[100];
int n,k,b,W,V;
void search(int top, int k, int wp, int vp, int b)
{
    int wp1=wp,vp1=vp;
    for (int i=top; i<n; i++)
    {
        if (wp1+w[i]<=b)
        {
            wp1+=w[i];
            vp1+=c[i];
        }
    }
    if (vp1>V)
    {
        V=vp1; W=wp1;
    }
    if (top==n) return;
    if (k==0) return;
    for (int i=top; i<n; i++)
    {
        if (wp+w[i]<=b)
        {
            search(i+1,k-1,wp+w[i],vp+c[i],b);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int p=0; p<t; p++)
    {
        scanf("%d%d%d",&b,&n,&k);
        for (int i=0; i<n; i++)
        {
            scanf("%d%d",&w[i],&c[i]);
            v[i]=(double)c[i]/w[i];
        }
        double temp;
        for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
        {
            if (v[i]<v[j])
            {
                temp=v[i]; v[i]=v[j]; v[j]=temp;
                temp=w[i]; w[i]=w[j]; w[j]=temp;
                temp=c[i]; c[i]=c[j]; c[j]=temp;
            }
        }
        W=0; V=0;
        search(0,k,0,0,b);
        printf("%d %d\n",W,V);
    }
    return 0;
}
