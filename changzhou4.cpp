#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
    int t;
    double xa,ya,za,xb,yb,zb,xc,yc,zc,xd,yd,zd,ans,f1ab,f2,f1cd,f3ab,f3cd,t1,t2,xm,ym,zm,xn,yn,zn;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&xa,&ya,&za,&xb,&yb,&zb,&xc,&yc,&zc,&xd,&yd,&zd);
        f1ab=(xb-xa)*(xb-xa)+(yb-ya)*(yb-ya)+(zb-za)*(zb-za);
        f1cd=(xd-xc)*(xd-xc)+(yd-yc)*(yd-yc)+(zd-zc)*(zd-zc);
        f2=(xb-xa)*(xd-xc)+(yb-ya)*(yd-yc)+(zb-za)*(zd-zc);
         f3ab=(xb-xa)*(xc-xa)+(yb-ya)*(yc-ya)+(zb-za)*(zc-za);
         f3cd=(xd-xc)*(xc-xa)+(yd-yc)*(yc-ya)+(zd-zc)*(zc-za);
         t1=(f3ab*f1cd-f3cd*f2)/(f1ab*f1cd-f2*f2);
         t2=(f3cd*f1ab-f2*f3ab)/(f2*f2-f1ab*f1cd);
         xm=t1*(xb-xa)+xa;
         ym=t1*(yb-ya)+ya;
         zm=t1*(zb-za)+za;
         xn=t2*(xd-xc)+xc;
         yn=t2*(yd-yc)+yc;
         zn=t2*(zd-zc)+zc;
         ans=sqrt((xm-xn)*(xm-xn)+(ym-yn)*(ym-yn)+(zm-zn)*(zm-zn));
         printf("%.6lf\n",ans);
         printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",xm,ym,zm,xn,yn,zn);
    }
    return 0;
}
