#include<iostream>
using namespace std;

int main()
{
    int t;
    double ans;
    while (cin>>t)
    {
        int tt;
        double m,n;
        for (int p=1; p<=t; p++)
        {
            cin>>tt>>m>>n;
            if (tt==0)
            {
                ans=1;
                for (int i=1; i<=n; i++)
                ans*=m;
                ans=(ans-1)/(m-1);
            }
            else
            {
                ans=1;
                for (int i=2; i<=n; i++)
                ans+=m/(m-i+1);
            }
            cout<<ans<<endl;
        }
    }
}
