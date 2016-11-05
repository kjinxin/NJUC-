#include<iostream>
using namespace std;

int g[500][500],ti;
const int t=10000000;

struct node
{
    int c,d,f;
};
void bfs(int s,int n)
{
    int d[500],pi[500];
    for (int i=0; i<n; i++)
    {
        d[i]=t;
        pi[i]=-2;
    }
    pi[s]=-1; d[s]=0;
    int l=0,r=0,a[500];
    a[l]=s;
    while (l<=r)
    {
        for (int i=0; i<n; i++)
        {
            if (g[a[l]][i]>0&&pi[i]==-2)
            {
                r++; a[r]=i;
                d[i]=d[a[l]]+g[a[l]][i];
                pi[i]=a[l];
            }
        }
        l++;
    }
    for (int i=0; i<n; i++)
    {
        cout<<i<<' ';
        if (d[i]==t) cout<<9999<<' '; else cout<<d[i]<<' ';
        if (pi[i]==-2) cout<<-1; else cout<<pi[i];
        cout<<endl;
    }
}

void search(node a[],int u,int n)
{
    ti++;
    a[u].d=ti;
    a[u].c=1;
    for (int i=0; i<n; i++)
    {
        if (g[u][i]>0&&a[i].c==0)
        {
            search(a,i,n);
        }
    }
    ti++;
    a[u].f=ti;
    a[u].c=2;
}
void dfs(int s,int n)
{
    node a[500];
    for (int i=0; i<n; i++)
    {
       a[i].c=0; a[i].d=0; a[i].f=0;
    }
    ti=0;
    for (int i=0; i<n; i++)
    {
        if (a[i].c==0)
        {
            search(a,i,n);
        }
    }
    for (int i=0; i<n; i++)
    cout<<i<<' '<<a[i].d<<' '<<a[i].f<<endl;
}
int main()
{
    int n,s;
    while (cin>>n>>s)
    {
        for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        cin>>g[i][j];
        bfs(s,n);
        dfs(s,n);
    }
    return 0;
}
