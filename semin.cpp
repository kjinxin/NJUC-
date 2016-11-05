#include<iostream>
using namespace std;

int a[100000];
int num;
int main()
{
    int max1=0,max2=0;
    cin>>num;
    for (int i=1; i<=num; i++)
    {
        cin>>a[i];
        if (a[i]>max1)
        {
            max2=max1;
            max1=a[i];
        }
        else
        if (a[i]>max2) max2=a[i];
    }
    cout<<max1<<' '<<max2<<endl;
    return 0;
}
