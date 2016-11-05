#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int f[5003][5003],m,n,p,q;
char st1[5010],st2[5010];
int main()
{
    cin>>st1>>st2;
    int m=strlen(st1),n=strlen(st2);
    f[0][0]=0;
    for (int i=1; i<=m; i++)
    f[i][0]=i;
    for (int i=1; i<=n; i++)
    f[0][i]=i;
    for (int i=0; i<m; i++)
    {
        p=i+1;
        for (int j=0; j<n; j++)
        {
            q=j+1;
            if (st1[i]==st2[j])
                f[p][q]=f[p-1][q-1];
            else
                f[p][q]=f[p-1][q-1]+1;
            if (f[p-1][q]+1<f[p][q])
            f[p][q]=f[p-1][q]+1;
            if (f[p][q-1]+1<f[p][q])
            f[p][q]=f[p][q-1]+1;
        }
    }
    cout<<f[m][n]<<endl;
    return 0;
}
