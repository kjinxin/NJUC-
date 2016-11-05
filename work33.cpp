#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int m,n,map[300][300],f[300][300],cf[300][300],a[100000],l,r,hash[300],fa[300];
int main()
{
    scanf("%d%d",&n,&m);
    int c,s,e;
    memset(map,0,sizeof(map));
    memset(f,0,sizeof(f));
    for (int i=0; i<n; i++)
    {
        cin>>s>>e>>c;
        map[s][e]+=c;
    }
    bool o=true;
    while (o)
    {
        memset(hash,0,sizeof(hash));
        memset(fa,0,sizeof(fa));
        l=r=1; a[l]=1; hash[1]=1;
        for(int i=1; i<=m; i++)
        for (int j=1; j<=m; j++)
        {
            if (map[i][j]>0)
                cf[i][j]=map[i][j]-f[i][j];
            else
            if (map[j][i]>0)
                cf[i][j]=f[j][i];
            else
                cf[i][j]=0;
        }
        bool k=false;
        while (l<=r)
        {
            int u=a[l];
            for (int i=1; i<=m; i++)
            {
                if ((hash[i]==0)&&(cf[u][i]>0))
                {
                    r++; a[r]=i; fa[i]=u; hash[i]=1;
                    if (i==m)
                    {
                        k=true;
                        break;
                    }
                }
            }
            if (k) break;
            l++;
        }
        if (!k) break;
        int j=m,min1=100000000;
        while (j!=1)
        {
            if (cf[fa[j]][j]<min1) min1=cf[fa[j]][j];
            j=fa[j];
        }
        j=m;
        while (j!=1)
        {
            if (map[fa[j]][j]>0)
            {
                f[fa[j]][j]+=min1;
            }
            j=fa[j];
        }
    }
    int ans=0;
    for (int i=2; i<=m; i++)
    ans+=f[1][i]-f[i][1];
    cout<<ans<<endl;
    return 0;
}
