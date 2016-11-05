#include<iostream>
#include<string>
using namespace std;

string st,st1,st2;
int f[20];
bool search(int top,int l,int r)
{
    if (r==l)
    {
        f[r]=1;
        st2=st1;
        for (int i=1; i<=st2.size(); i++)
        {
            if (f[i]==0)
            {
                st1+=st2[i];
            }
        }
        for (int i=1; i<=st1.size(); i++)
        f[i]=0;
        if (st1.size()==0) return true;
        if (top-1==0) return false;
        search(top-1,1,st1.size());
    }
    for (int i=r; i>l; i--)
    {
        if (st[i]==st[l])
        {
            f[i]=1; f[l]=1;
            search(top,l+1,i-1);
            break;
        }
    }
    search(top,l+1,r);
    return false;
}
int main()
{
    int t;
    cin>>t;
    for (int p=1; p<=t; p++)
    {
        int ans=0;
        cin>>st;
        for (int top=1; top<=st.size(); top++)
        {
            st1=st;
            for (int i=1; i<=st.size(); i++)
            f[i]=0;
            bool o=search(top,1,st.size());
            if (o)
            {
                cout<<top<<endl;
                break;
            }
        }
    }
}
