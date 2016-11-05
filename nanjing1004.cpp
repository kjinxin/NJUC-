#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,g[120][120],hash[120],p[5][120];
int main()
{
    while (scanf("%d",&n) != EOF)
    {
        memset(g, 0, sizeof(g));
        memset(hash,0,sizeof(hash));
        for (int i=1; i<=n; i++)
        {
            int temp;
            while (scanf("%d",&temp))
            {
                if (temp == 0) break;
                g[i][temp] = 1;
            }
            g[i][i]=1;
        }
        bool o=true;
        int top1=1,top2=0;
        hash[1]=1;
        p[1][1]=1;
        while (o)
        {
            bool k=true;
            for (int t=1; t<=top1; t++)
            {
                int j=p[1][t];
                for (int i=1; i<=n; i++)
                {
                    if (g[j][i]==0||g[i][j]==0)
                    {
                        if (hash[i]==0)
                        {
                            hash[i]=2; top2++;
                            p[2][top2]=i;
                            k=false;
                        }
                        else
                        if (hash[i]==1)
                        {
                            o=false; break;
                        }
                    }
                }
            }
            for (int i=1; i<top2; i++)
            for (int j=i+1; j<=top2; j++)
            if (g[p[2][i]][p[2][j]]==0||g[p[2][j]][p[2][i]]==0)
            {
                o=false; break;
            }
            for (int t=1; t<=top2; t++)
            {
                int j=p[2][t];
                for (int i=1; i<=n; i++)
                {
                    if (g[j][i]==0||g[i][j]==0)
                    {
                        if (hash[i]==0)
                        {
                            hash[i]=1; top1++;
                            p[1][top1]=i;
                            k=false;
                        }
                        else
                        if (hash[i]==2)
                        {
                            o=false; break;
                        }
                    }
                }
            }
            for (int i=1; i<top1; i++)
            for (int j=i+1; j<=top1; j++)
            if (g[p[1][i]][p[1][j]]==0||g[p[1][j]][p[1][i]]==0)
            {
                o=false; break;
            }
            if (k)
            {
                for (int i=1; i<=n; i++)
                {
                    if (hash[i]==0)
                    {
                        k=false;
                        top1++;
                        hash[i]=1;
                        p[1][top1]=i;
                        break;
                    }
                }
            }
            if (k) break;
        }
        if (o) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
