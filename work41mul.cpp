#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int a[600],b[600],c[1200],m,n;
    bool o=true;
    memset(c,0,sizeof(c));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    string st;
    cin>>st;
    m=st.size();
    if (st[0]=='-') o=!o;
    for (int i=m-1; i>=(st[0]=='-'); i--)
    {
        a[m-i]=st[i]-'0';
    }
    cin>>st;
    n=st.size();
    if (st[0]=='-') o=!o;
    for (int i=n-1; i>=(st[0]=='-'); i--)
    b[n-i]=st[i]-'0';
    for (int i=1; i<=m; i++)
    for (int j=1; j<=n; j++)
    {
        c[i+j-1]+=a[i]*b[j];
        c[i+j]+=c[i+j-1]/10;
        c[i+j-1]%=10;
    }
    for (int i=1; i<=m+n; i++)
    {
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    int top=m+n+1;
    while (top>1&&c[top]==0)
    top--;
    if (!o) cout<<'-';
    for (int i=top; i>=1; i--)
    cout<<c[i];
    cout<<endl;
}
