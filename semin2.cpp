#include<iostream>
using namespace std;

int a[100000],num;

void calculate(int l,int r,int& max1,int& max2)
{
    if (r-l<2)
    {
        if (r==l)
        {
            max1=a[l];max2=a[l];
        }
        else
        {
            if (a[l]>a[r])
            {
                max1=a[l]; max2=a[r];
            }
            else
            {
                max1=a[r]; max2=a[l];
            }
        }
        return;
    }
    int mid=(l+r)/2;
    int max01,max02,max11,max12;
    calculate(l,mid,max01,max02);
    calculate(mid+1,r,max11,max12);
    if (max01>max11)
    {
        max1=max01;
        if (max11>max02)
            max2=max11;
        else max2=max02;
    }
    else
    {
        max1=max11;
        if (max01>max12)
            max2=max01;
        else max2=max12;
    }
    return;
}
int main()
{
    cin>>num;
    for (int i=1; i<=num; i++) cin>>a[i];
    int max1=0,max2=0;
    calculate(1,num,max1,max2);
    cout<<max1<<' '<<max2<<endl;
    return 0;
}
