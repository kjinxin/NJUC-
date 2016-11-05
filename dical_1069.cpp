#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;
int n,ans;
struct node
{
    double x,y;
};
double a[100];
node pos[100];

void initial()
{
    for (int i=0; i<n; i++)
    {
        scanf("%lf%lf",&pos[i].x,&pos[i].y);
    }
    return;
}

void work()
{
    int num,top,t;
    if (n>1) ans=2; else ans=1;
    for (int i=0; i<n; i++)
    {
        top=0; t=0; num=0;
        for (int j=0; j<n; j++)
        {
            if (pos[i].x==pos[j].x&&pos[i].y==pos[j].y)
            {
                num++;
            }
            else
            {
                if (pos[i].x==pos[j].x)
                t++;
                else
                {
                    a[top]=(pos[i].y-pos[j].y)/(pos[i].x-pos[j].x);
                    top++;
                }
            }
        }
        if (t+num>ans) ans=t+num;
        sort(a,a+top);
        t=1;
        for (int j=1; j<top; j++)
        {
           if (a[j]==a[j-1])
           {
                t++;
                if (t+num>ans) ans=t+num;
           }
           else
           {
               if (t+num>ans) ans=t+num;
               t=1;
           }
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    while (n!=0)
    {
        initial();
        work();
        printf("%d\n",ans);
        scanf("%d",&n);
    }
    return 0;
}
