#include<cstdio>
#include<cstring>
typedef struct
{
   int l,r,lab;
}node;
int main()
{
    int T,m,n,k;
    node data[32];
    scanf("%d",&T);
    int ans[32],fuzhi[32];
    for (int p = 0; p < T; p++)
    {
        scanf("%d%d%d",&m, &n, &k);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&data[i].lab, &data[i].l, &data[i].r);
        }
        for (int i = 0; i < k; i++)
        {
            memset(ans,0,sizeof(ans));
            for (int j = 1; j <= n; j++)
            scanf("%d",&fuzhi[j]);
            ans[1]=1;
            for (int j = 0; j < m-2; j++)
            {
                ans[data[j].l]+=ans[j+1]*(1-fuzhi[data[j].lab]);
                ans[data[j].r]+=ans[j+1]*fuzhi[data[j].lab];
            }
            if (i!=k-1)
            printf("%d ",ans[m]);
            else
            if (p!=T-1) printf("%d\n",ans[m]);
            else printf("%d",ans[m]);
        }
    }
    return 0;
}
