#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

//ifstream fin("1.txt");
const double hu=0.6180339887;
int main()
{
    int a[200000],b[200000],n,m;
    while(cin>>n>>m)
    {
        for (int i=0; i<=m; i++)
        a[i]=-1;
        for (int i=1; i<=n; i++)
        {
            cin>>b[i];
        }
        int ans=0;
        for (int i=1; i<=n; i++)
        {
            int t=b[i]%m;
            if (a[t]==-1)
                  a[t]=1;
            else
                ans++;
        }
        cout<<ans<<endl;
        for(int i=0; i<=m; i++)
        a[i]=-1;
        ans=0;
        for(int i=1; i<=n; i++)
        {
            int t=floor(m*(b[i]*hu-int(b[i]*hu)));
            if (a[t]==-1)
            {
                a[t]=1;
            }
            else ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
