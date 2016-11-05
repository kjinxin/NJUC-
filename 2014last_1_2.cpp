#include<cstdio>
#include<cstring>

void search(int t, int ans[], int fa[], int hash[])
{
    if (hash[t]==1) return;
    if (fa[t]=t)
    {
        hash[t]=1; return;
    }
    if (hash[fa[t]]==0)
        search(fa[t],ans,fa,hash);
    if (ans[t]<ans[fa[t]]+ans[t]) ans[t]=ans[fa[t]]+ans[t];
    hash[t]=1;

}
int main()
{
    int K;
    scanf("%d",&K);
    int ans[102],fa[102],hash[102];
    for (int p=0; p<K; p++)
    {
        int n;
        scanf("%d",&n);
        for (int i=0; i<=n; i++)
        fa[i]=i;
        memset(ans,0,sizeof(ans));
        memset(hash,0,sizeof(hash));
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&ans[i]);
            int num,t;
            scanf("%d",&num);
            for (int j=0; j<num; j++)
            {
                scanf("%d",&t);
                fa[t]=i;
            }
        }
        for (int i=1; i<=n; i++)
        search(i,ans,fa,hash);
        int max=-100000;
        for (int i=1; i<=n; i++)
        if (max<ans[i])
        max=ans[i];
        printf("%d\n",max);
    }
}
