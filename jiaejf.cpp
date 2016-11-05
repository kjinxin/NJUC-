#include <cstdio>
#include <cstring>
int t[320],wei[320],ans[320][3];
int edge[320][320];
void search(int k)
{
    if (t[k]==0)
    {
            ans[k][1]=wei[k]>0?wei[k]:0;
            ans[k][2]=0;
    }
    else
    for (int col=1; col<=t[k]; col++)
    {
        search(edge[k][col]);
        if (ans[edge[k][col]][1]+wei[k]>=ans[k][1])
        {
            ans[k][2]=ans[k][1];
            ans[k][1]=ans[edge[k][col]][1]+wei[k];
        }
        else
        if (ans[edge[k][col]][1]+wei[k]>ans[k][2])
            ans[k][2]=ans[edge[k][col]][1]+wei[k];
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int n;
    for (int p=1; p<=T; p++)
    {
        scanf("%d",&n);
        int hash[320];
        memset(hash,0,sizeof(hash));
        for (int col=1; col<=n; col++)
        {
            scanf("%d",&wei[col]);
            scanf("%d",&t[col]);
            for (int row=1;row<=t[col];row++)
            {
                scanf("%d",&edge[col][row]);
                hash[edge[col][row]]=1;
            }
        }
        int k;
        for (int col=1; col<=n; col++)
        {
            ans[col][1]=0;
            ans[col][2]=0;
            if (hash[col]==0) k=col;
        }
        search(k);
        int m=-1000;
        for (int col=1; col<=n; col++)
        if (m<ans[col][1]+ans[col][2]-wei[col])
            m=ans[col][1]+ans[col][2]-wei[col];
        printf("%d\n",m);
    }
    return 0;
}
