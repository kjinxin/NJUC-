#include<cstdio>
void gcdextended(int a,int b,int& d,int& r,int& s)
{
    if (b==0)
    {
        d=a; r=1; s=0; return;
    }
    int r1,s1;
    gcdextended(b,a%b,d,r1,s1);
    r=s1; s=r1-a/b*s1;
    return;
}
int main()
{
    int a,b,r,s,d;
    while (scanf("%d%d",&a,&b))
    {
        gcdextended(a,b,d,r,s);
        printf("%d %d %d\n",d,r,s);
    }
}
