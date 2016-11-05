#include<iostream>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long num=1;
    while (n%2==0)
    {
        num*=2;
        n/=2;
    }
    long long k=n/num;
    cout<<k<<endl;
    cout<<k*(k-3)/2+n<<endl;
    cout<<n<<endl;
}
