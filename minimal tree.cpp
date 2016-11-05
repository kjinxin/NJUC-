#include<iostream>
using namespace std;
struct cordinate
{
    int v,u,value;
};
int n,m;
cordinate a[100000];
int fa[1000];
void qsort(int m,int n)
{
    int l1=m,l2=n,x=a[(l2+l1)/2].value;
    cordinate t;
    while (l1<=l2)
    {
        while (a[l1].value<x) l1++;
        while (a[l2].value>x) l2--;
        if (l1<=l2)
        {
            t=a[l1]; a[l1]=a[l2]; a[l2]=t; l1++; l2--;
        }
    }
    if (l1<n) qsort(l1,n);
    if (l2>m) qsort(m,l2);
}
void init()
{
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].value;
    }
    qsort(1,m);
    for (int i=1; i<=n; i++)
    fa[i]=i;
}
int getfa(int  v)
{
    if (fa[v]==v) return v; else return fa[v];
}
void change(int fa1,int v)
{
    if (fa[v]==v)
    {
        fa[v]=fa1; return;
    }
    change(fa1,fa[v]);
    fa[v]=fa1;
}
int main()
{
    init();
    int j=1,i=1,fa1,fa2,ans=0;
    while (i<n)
    {
        fa1=getfa(a[j].v);
        fa2=getfa(a[j].u);
        if (fa1!=fa2)
        {
            change(fa1,a[j].u);
            ans+=a[j].value;
            i++;
        }
        j++;
    }
    cout<<ans<<endl;
}
