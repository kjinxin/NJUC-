#include<iostream>
using namespace std;

int ans;

void cho(int t)
{
    if (t<7) return;
    ans+=t/7;
    cho(t%7+t/7);
    return;
}
int main()
{
   int t;
   while (cin>>t)
   {
       ans=t;
       cho(t);
       cout<<ans<<endl;
   }
   return 0;
}
