#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int t;
string T,P;
int m,n,ans,pi[10100];

void computerpi(int m)
{
    pi[0]=-1;
    int k=-1;
    for (int q=1; q<m; q++)
    {
        while (k>=0&&P[k+1]!=P[q])
        k=pi[k];
        if (P[k+1]==P[q])
        k++;
        pi[q]=k;
    }
}
void KMP()
{
    n=T.size();
    m=P.size();
    computerpi(m);
    int q=-1;
    for (int i=0; i<n; i++)
    {
        while (q>=0&&P[q+1]!=T[i])
            q=pi[q];
        if (P[q+1]==T[i])
            q++;
        if (q==m-1)
        {
            ans++;
            q=pi[q];
        }
    }
}
int main()
{
    scanf("%d",&t);
    for (int i=0; i<t; i++)
    {
         cin>>P>>T;
         ans=0;
         KMP();
         printf("%d\n",ans);
    }
}
