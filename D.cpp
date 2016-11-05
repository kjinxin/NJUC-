#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for (int i=1; i<=t; i++)
    {
        long double xa,ya,za,xb,yb,zb,xc,yc,zc,xd,yd,zd;
        scanf("%Lf",&xa);
        cout<<xa<<endl;
        scanf("%Lf",&ya);
        scanf("%Lf",&za);
        scanf("%Lf",&xb);
        scanf("%Lf",&yb);
        scanf("%Lf",&zb);
        scanf("%Lf",&xc);
        scanf("%Lf",&yc);
        scanf("%Lf",&zc);
        scanf("%Lf",&xd);
        scanf("%Lf",&yd);
        scanf("%Lf",&zd);
        printf("%Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf\n",xa,ya,za,xb,yb,zb,xc,yc,zc,xd,yd,zd);
        long double f1ab=(xb-xa)*(xb-xa)+(yb-ya)*(yb-ya)+(zb-za)*(zb-za);
        long double f1cd=(xd-xc)*(xd-xc)+(yd-yc)*(yd-yc)+(zd-zc)*(zd-zc);
        long double f2=(xb-xa)*(xd-xc)+(yb-ya)*(yd-yc)+(zb-za)*(zd-zc);
        long double f3ab=(xb-xa)*(xc-xa)+(yb-ya)*(yc-ya)+(zb-za)*(zc-za);
        long double f3cd=(xd-xc)*(xc-xa)+(yd-yc)*(yc-ya)+(zd-zc)*(zc-za);
        long double t1=(f3ab*f1cd-f3cd*f2)/(f1ab*f1cd-f2*f2);
        long double t2=(f3cd*f1ab-f2*f3ab)/(f2*f2-f1ab*f1cd);
        long double xm=t1*(xb-xa)+xa;
        long double ym=t1*(yb-ya)+ya;
        long double zm=t1*(zb-za)+za;
        long double xn=t2*(xd-xc)+xc;
        long double yn=t2*(yd-yc)+yc;
        long double zn=t2*(zd-zc)+zc;
        long double ans=sqrt((xm-xn)*(xm-xn)+(ym-yn)*(ym-yn)+(zm-zn)*(zm-zn));
		printf("%.6Lf\n",ans);
        cout<<xm<<' '<<ym<<' '<<zm<<endl;
		printf("%.6Lf %.6Lf %.6Lf %.6Lf %.6Lf %.6Lf\n",xm,ym,zm,xn,yn,zn);
    }
    return 0;
}
