#include<cstdio>

int getfa(int u,int fa[])
{
    if (fa[u]==u) return u;
    else
    {
        fa[u]=getfa(fa[u],fa);
        return fa[u];
    }
}
int main()
{
    typedef struct
    {
        int u,v;
    } node;
    node a[52];
    int fa[22],v,l,n,pp,ans[52],num,hash[52],nn,bianhao,lunshu,v1,u1;
    scanf("%d",&n);
    for (int p=0; p<n; p++)
    {
        scanf("%d%d",&v,&l);
        for (int i=0; i<l; i++)
        {
            scanf("%d:%d",&a[i].u,&a[i].v);
            if (a[i].u>a[i].v)
            {
                pp=a[i].u; a[i].u=a[i].v; a[i].v=pp;
            }
            hash[i]=0;
        }
        hash[l]=0;
        for (int i=0; i<=v; i++) fa[i]=i;
        nn=l; lunshu=1;
        while (nn>0)
        {
            num=0;
            bianhao=(32761*lunshu)%nn;
            for (int i=0; i<l; i++)
            if (hash[i]==0)
            {
                if (bianhao==0)
                {
                    u1=getfa(a[i].u,fa); v1=getfa(a[i].v,fa); break;
                }
                bianhao--;
            }
            for (int i=0; i<l; i++)
            if ((hash[i]==0)&&(u1==getfa(a[i].u,fa)&&v1==getfa(a[i].v,fa))||(v1==getfa(a[i].u,fa)&&u1==getfa(a[i].v,fa)))
            {
                hash[i]=1; ans[num]=i; num++;
            }
            fa[v1]=u1;
            lunshu++;
            nn-=num;
        }
        for (int i=0; i<num-1; i++)
        printf("%d:%d ",a[ans[i]].u,a[ans[i]].v);
        if (p!=n-1) printf("%d:%d\n",a[ans[num-1]].u,a[ans[num-1]].v);
        else printf("%d:%d",a[ans[num-1]].u,a[ans[num-1]].v);
    }
    return 0;
}
