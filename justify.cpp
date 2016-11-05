#include<iostream>
using namespace std;

int main()
{
    double pi=3.1415926,r=8,vc,vm;
    while (cin>>vc>>vm)
    {
        double p0,pq8,pv;
        pq8=1/r*(vc*vm/2/pi-vm*vm/4);
        p0=vm*vm/2/r;
        pv=vc*vm/pi/r;
        cout<<pi*vm/2/vc<<endl;
    }
    return 0;
}
