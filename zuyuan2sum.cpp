#include<cstdio>
#include<cstdarg>

int mysum(int a...)
{
    double sum=0;
    va_list ap;
    va_start(ap,a);
    for (int i=0; i<a; i++)
    {
        sum+=va_arg(ap,double);
    }
    return sum;
}
int main()
{
    double ans1,ans2;
    ans1=mysum(2,1.0,2.0);
    ans2=mysum(4,1.0,2.0,3.0,4.0);
    printf("%lf %lf\n",ans1,ans2);
}
