#include<iostream>
using namespace std;

int main()
{
    int l1=1000000,l2=0,r1=1000000,r2=0;
    int n;
    cin>>n;
    int x1,y1,x2,y2,sum=0;
    for (int i=1; i<=n; i++)
    {
        cin>>x1>>y1>>x2>>y2;
        if (x1<l1) l1=x1;
        if (y1<r1) r1=y1;
        if (x2>l2) l2=x2;
        if (y2>r2) r2=y2;
        sum+=(x2-x1)*(y2-y1);
    }
    int t=l2-l1;
    if (t<r2-r1) t=r2-r1;
    if (sum==t*t)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
