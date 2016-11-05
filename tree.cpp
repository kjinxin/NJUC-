#include<cstdio>

int fa[200],a[200],b[200];
int main()
{
    int K;
    scanf("%d",&K);
    for (int p=0; p<K; p++)
    {
        int n;
        scanf("%d",&n);
        for (int i=0; i<=n; i++)
        fa[i]=i;
        for (int i=0; i<n; i++)
        {
            int u,v;
            scanf("%d",&u);
            int num1;
            scanf("%d",&num1);
            for (int j=0; j<num1; j++)
            {
                scanf("%d",&v);
                fa[v]=u;
            }
        }
        int num1=0,num2=0;
        int u,v;
        scanf("%d%d",&u,&v);
        a[num1]=u; b[num2]=v;
        while (fa[u]!=u)
        {
            num1++;
            a[num1]=fa[u];
            u=fa[u];
        }
        while (fa[v]!=v)
        {
            num2++;
            b[num2]=fa[v];
            v=fa[v];
        }
        while (num1>=0&&num2>=0&&a[num1]==b[num2])
        {
            num1--;
            num2--;
        }
        num1++;
        printf("%d\n",a[num1]);
    }
    return 0;
}
