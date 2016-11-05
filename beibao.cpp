#include<iostream>
using namespace std;

int c,n,q[1000],pro[1000][1000],f[1000],w[1000],p[1000],fa[1000],ch[1000],num=0;

void init()
{
    cin>>n>>c;
    int q1,w1,p1;
    for (int i=1; i<=n; i++)
    {
        cin>>q1>>w1>>p1;
        for (int j=1; j<=q1; j++)
        {
            num++; fa[num]=i;
            w[num]=w1; p[num]=p1;
        }
    }
    for (int i=0; i<=c; i++)
    for (int j=0; j<=num; j++)
    pro[i][j]=0;
}
int main()
{
    init();
    for (int i=1; i<=num; i++)
    {
    for (int j=1; j<=c; j++)
    {
        pro[i][j]=pro[i-1][j];
        if ((j>=w[i])&&(pro[i][j]<pro[i-1][j-w[i]]+p[i]))
        {
            pro[i][j]=pro[i-1][j-w[i]]+p[i];
        }
    }
    cout<<pro[i][c]<<endl;
    }
    cout<<pro[num][c]<<endl;
    return 0;
}
