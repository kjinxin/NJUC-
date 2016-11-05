#include<cstdio>
#include<cmath>
#include<cstring>
const double pi=acos(-1);
double  a[2][10000],b[2][10000],A[2][10000],B[2][10000],c[2][10000],C[2][10000],f[100];
int n1,n2,n;

int rev(int k,int t)
{
    int tt=0;
    do
    {
        if (k%2==1)
        tt+=f[t];
        k/=2;
        t--;
    }while (k>0);
    return tt;
}

void bit_reverse_copy(double a[][10000],double A[][10000],int t)
{
    for (int k=0; k<n; k++)
    {
        int j=rev(k,t);
        A[0][j]=a[0][k]; A[1][j]=a[1][k];
    }
}
void iterative_fft(double a[][10000],double A[][10000],int pt)
{
    int t=0;
    while (f[t]<n) t++;
    t--;
    bit_reverse_copy(a,A,t);
    double wmr,wmi,wr,wi,wr1,wi1;
    for (int s=1; s<=t+1; s++)
    {
        int m=f[s];
        wmr=cos(pt*2.0*pi/m); wmi=sin(pt*2.0*pi/m);
        for (int k=0; k<n; k+=m)
        {
            wr=1; wi=0;
            for (int j=0; j<m/2; j++)
            {
                double tr,ti;
                tr=wr*A[0][k+j+m/2]-wi*A[1][k+j+m/2]; ti=wr*A[1][k+j+m/2]+wi*A[0][k+j+m/2];
                double ur,ui;
                ur=A[0][k+j]; ui=A[1][k+j];
                A[0][k+j]=tr+ur; A[1][k+j]=ti+ui;
                A[0][k+j+m/2]=ur-tr; A[1][k+j+m/2]=ui-ti;
                wr1=wr*wmr-wi*wmi; wi1=wr*wmi+wi*wmr;
                wr=wr1; wi=wi1;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n1,&n2);
    for (n=1;n<n1+n2;n=n<<1);
    memset(a,0,sizeof(a)); memset(A,0,sizeof(A));
    memset(b,0,sizeof(b)); memset(B,0,sizeof(B));
    memset(c,0,sizeof(c)); memset(C,0,sizeof(C));
    for (int i=0; i<n1; i++)
    scanf("%lf",&a[0][i]);
    for (int i=0; i<n2; i++)
    scanf("%lf",&b[0][i]);
    f[0]=1;
    for (int i=1; i<18; i++)
    f[i]=f[i-1]*2;
    iterative_fft(a,A,1);
    iterative_fft(b,B,1);
    for (int i=0; i<n; i++)
    {
        C[0][i]=A[0][i]*B[0][i]-A[1][i]*B[1][i];
        C[1][i]=A[0][i]*B[1][i]+A[1][i]*B[0][i];
    }
    iterative_fft(C,c,-1);
    for (int i=0; i<n1+n2-1; i++)
    printf("%.6lf ",c[0][i]/n);
    printf("\n");
    return 0;
}
