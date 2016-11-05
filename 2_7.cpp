#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdio>
using namespace std;

ifstream fin("2_6.txt");
int main()
{
    int t;
    double x[200],y[200],z[200];
    fin>>t;
    for (int p=1; p<=t; p++)
    {
        int n;
        fin>>n;
        for (int i=1; i<=3*n; i++)
        fin>>x[i]>>y[i]>>z[i];
        bool o=true;
        double min1=100000000;
        for (int i=1; i<=n-1; i++)
        {
            for (int j=i+1; j<=n; j++)
            {
                double x1,y1,z1,x2,y2,z2,r1,r2;
                int t1=(i-1)*3;
                x1=x[t1+1]-x[t1+2];
                y1=y[t1+1]-y[t1+2];
                z1=z[t1+1]-z[t1+2];
                x2=x[t1+1]-x[t1+3];
                y2=y[t1+1]-y[t1+3];
                z2=z[t1+1]-z[t1+3];
                r1=sqrt((x[t1+1]-x[t1+3])*(x[t1+1]-x[t1+3])+(y[t1+1]-y[t1+3])*(y[t1+1]-y[t1+3])+(z[t1+1]-z[t1+3])*(z[t1+1]-z[t1+3]));
                double a1,b1,c1,a2,b2,c2;
                a1=y1*z2-z1*x2;
                b1=z1*x2-x1*z2;
                c1=x1*y2-y1*x2;
                int t2=(j-1)*3;
                x1=x[t2+1]-x[t2+2];
                y1=y[t2+1]-y[t2+2];
                z1=z[t2+1]-z[t2+2];
                x2=x[t2+1]-x[t2+3];
                y2=y[t2+1]-y[t2+3];
                z2=z[t2+1]-z[t2+3];
                r2=sqrt((x[t2+1]-x[t2+3])*(x[t2+1]-x[t2+3])+(y[t2+1]-y[t2+3])*(y[t2+1]-y[t2+3])+(z[t2+1]-z[t2+3])*(z[t2+1]-z[t2+3]));
                a2=y1*z2-z1*x2;
                b2=z1*x2-x1*z2;
                c2=x1*y2-y1*x2;
                double a,b,c;
                a=b1*c2-c1*b2;
                b=c1*a2-a1*c2;
                c=a1*b2-b1*a2;
                x1=x[t1+1]-x[t2+1];
                y1=y[t1+1]-y[t2+1];
                z1=z[t1+1]-z[t2+1];
                double d=sqrt(a*a+b*b+c*c);
                double temp=a*x1+b*y1+c*z1;
                if (temp<0) temp=-temp;
                double ans=temp/d-r1-r2;
                if (ans<min1) min1=ans;
                if (ans<=0)
                {
                    cout<<"Lucky"<<endl;
                    o=false;
                    break;
                }
            }
            if (!o) break;
        }
        if (o)
        {
            printf("%.2f",min1);
            cout<<endl;
        }
    }
    return 0;
}
