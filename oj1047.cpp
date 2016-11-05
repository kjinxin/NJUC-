#include<iostream>
#include<fstream>
using namespace std;


struct node
{
    int x,y,w;
};
const int max1=100000000;
node g[4200];
int st[4200],fi[4200],hash[1111],a[1111],data[1111],po[1111],map[1001][1001];
int t,n,num=0,top;

void init()
{
    for (int i=1; i<=n; i++)
    {
        hash[i]=max1;
        st[i]=0; fi[i]=0;
        a[i]=i; data[i]=max1; po[i]=i;
    }
    hash[n]=0;
    g[0].x=0; g[num+1].x=n+1;
    for (int i=1; i<=num+1; i++)
    {
        if (g[i].x!=g[i-1].x)
        {
            fi[g[i-1].x]=i-1;
            st[g[i].x]=i;
        }
    }
    if (st[n]!=0)
    for (int i=st[n]; i<=fi[n]; i++)
    {
        data[g[i].y]=g[i].w;
    }
    data[n]=0;
    top=n-1;
}

void minheap(int i)
{
    int l,r,small,tt;
    l=i*2; r=i*2+1;
    if (l<=top&&data[l]<data[i])
        small=l;
    else small=i;
    if (r<=top&&data[r]<data[small])
        small=r;
    if (small!=i)
    {
        tt=data[i]; data[i]=data[small]; data[small]=tt;
        tt=a[i]; a[i]=a[small]; a[small]=tt;
        po[a[i]]=i; po[a[small]]=small;
        minheap(small);
    }
}

void up(int i)
{
    int tt,small;
    while(i>1)
    {
        small=i/2;
        if (data[small]>data[i])
        {
            tt=data[i]; data[i]=data[small]; data[small]=tt;
            tt=a[i]; a[i]=a[small]; a[small]=tt;
            po[a[i]]=i; po[a[small]]=small;
            i=small;
        }
        else break;
    }
}
void jiandui()
{
    for (int i=top/2; i>=1; i--)
       minheap(i);
}


int main()
{
    cin>>t>>n;
    int u,v,w;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        map[i][j]=max1;
    }
    for (int i=0; i<t; i++)
    {
        cin>>u>>v>>w;
        if (map[u][v]>w)
        {
            map[u][v]=w;
            map[v][u]=w;
        }
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        if (map[i][j]!=max1)
        {
            num++;
            g[num].x=i; g[num].y=j; g[num].w=map[i][j];
        }
    }
    init();
    jiandui();
    for (int i=1; i<n-1; i++)
    {
        u=a[1]; hash[u]=data[1];
        data[1]=data[top]; a[1]=a[top]; po[a[1]]=1;
        top--;
        minheap(1);
        if (st[u]!=0)
        for (int i=st[u]; i<=fi[u]; i++)
        {
            v=g[i].y;
            if (hash[v]==max1&&data[po[v]]>hash[u]+g[i].w)
            {
                data[po[v]]=hash[u]+g[i].w;
                up(po[v]);
            }
        }
    }
    hash[a[1]]=data[1];
    if (hash[1]<max1) cout<<hash[1]<<endl;
    else cout<<-1<<endl;
    return 0;
}
