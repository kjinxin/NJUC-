#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct node
{
    int x,y;
};
struct node1
{
    int st,fi;
};
int ans[5000];
node g[5000];
node1 xin[5000];
int hash[501][501],f,top=0;
void qsort(int m,int n)
{
    int l1,l2,x,y; node t;
    l1=m; l2=n; x=g[(l1+l2)/2].x; y=g[(l1+l2)/2].y;
    do
    {
        while (g[l1].x<x || g[l1].x==x && g[l1].y<y) l1++;
        while (g[l2].x>x || g[l2].x==x && g[l2].y>y) l2--;
        if (l1<=l2)
        {
            t=g[l1]; g[l1]=g[l2]; g[l2]=t; l1++; l2--;
        }
    }while (l1<=l2);
    if (l1<n) qsort(l1,n);
    if (l2>m) qsort(m,l2);
}
void dfs(int t)
{
    for (int i=xin[t].st; i<=xin[t].fi; i++)
    {
        if (hash[t][g[i].y]>0)
        {
            hash[t][g[i].y]--;
            hash[g[i].y][t]--;
            dfs(g[i].y);
        }
    }
    ans[0]++;
    ans[ans[0]]=t;
}
void print()
{
    for (int i=ans[0]; i>=1; i--)
    cout<<ans[i]<<endl;
}
int main()
{
    memset(g,0,sizeof(g));
    memset(xin,0,sizeof(xin));
    memset(hash,0,sizeof(hash));
    scanf("%d",&f);
    int x,y;
    for (int i=0; i<f; i++)
    {
        scanf("%d%d",&x,&y);
        top++; g[top].x=x; g[top].y=y; hash[x][y]++;
        //top++; g[top].y=x; g[top].x=y; hash[y][x]++;
    }
    qsort(1,top);
    xin[g[1].x].st=1;
    for (int i=2; i<=top; i++)
    {
        if (g[i].x!=g[i-1].x)
        {
            xin[g[i-1].x].fi=i-1;
            xin[g[i].x].st=i;
        }
    }
    xin[g[top].x].fi=top;
    bool o=true; int j;
    for (int i=1; i<=500; i++)
    {
        if ((xin[i].fi-xin[i].st+1)%2==1 && xin[i].st!=0)
        {
            j=i; o=false; break;
        }
    }
    if (o) dfs(g[1].x);
    else dfs(j);
    print();
    return 0;
}
