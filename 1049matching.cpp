#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
using namespace std;
const int maxm=2000;
int n,m,vis[maxm];
int Link[maxm];
bool map[maxm][maxm];
int hash[100][100];
char g[100][100];
const int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
//ofstream fout("2.txt");
//ifstream fin("1.txt");
bool find(int i)
{
    for (int j=0; j<m+n; j++)
    {
        if (map[i][j]&&!vis[j])
        {
            vis[j]=true;
            if (Link[j]==0||find(Link[j]))
            {
                Link[j]=i;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    memset(Link,0,sizeof(Link));
    for (int i=0; i<m+n; i++)
    {
        memset(vis,0,sizeof(vis));
        bool t=find(i);
    }
}

int main()
{
    int t,p,q;
    cin>>t;
    for (int k=1; k<=t; k++)
    {
        cin>>p>>q; n=0;
        memset(map,0,sizeof(map));
        for (int i=1; i<=p; i++)
        for (int j=1; j<=q; j++)
        {
            cin>>g[i][j];
            if (g[i][j]=='*')
            {
                hash[i][j]=n; n++;
            }
        }
        m=n;
        int x1,y1;
        for (int i=1; i<=p; i++)
        for (int j=1; j<=q; j++)
        {
            if (g[i][j]=='*')
            for (int pq=0; pq<4; pq++)
            {
                x1=i+dx[pq]; y1=j+dy[pq];
                if (x1>0&&x1<=p&&y1>0&&y1<=q)
                {
                    if (g[x1][y1]=='*')
                    {
                         map[hash[i][j]][hash[x1][y1]+n]=1;
                         map[hash[x1][y1]+n][hash[i][j]]=1;
                    }
                }
            }
        }
        solve();
        int ans=0;
        for (int i=0; i<n; i++)
        if (Link[i]!=0)
        {
            ans++;
        }
        cout<<n-ans/2<<endl;
    }
    return 0;
}
