#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("test3.in");
ofstream fout("test23.out");
void juplu(int n,int c[][50],int a[][50],int b[][50])
{#include<iostream>
using namespace std;


void juplu(int n,int c[][50],int a[][50],int b[][50])
{
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        c[i][j]=a[i][j]+b[i][j];
    }
}

void fuzhi(int n,int c[][50],int cr1,int cr2,int cl1,int cl2,int a[][50],int ar1,int ar2,int al1,int al2)
{
    int ar,cr,al,cl;
    for (int i=1; i<=n; i++)
    {
        cr=cr1+i-1; ar=ar1+i-1;
        for (int j=1; j<=n; j++)
        {
            cl=cl1+j-1; al=al1+j-1;
            c[cr][cl]=a[ar][al];
        }
    }
}
void search(int n,int c[][50],int a[][50],int b[][50])
{
    if (n==1)
    {
        c[1][1]=a[1][1]*b[1][1];
        return;
    }
    int a11[50][50],a12[50][50],a21[50][50],a22[50][50],b11[50][50],b12[50][50],b21[50][50],b22[50][50];
    int p1[50][50],p2[50][50],p3[50][50],p4[50][50],p5[50][50],p6[50][50],p7[50][50],p8[50][50];
    int c11[50][50],c12[50][50],c21[50][50],c22[50][50];
    fuzhi(n/2,a11,1,n/2,1,n/2,a,1,n/2,1,n/2);
    fuzhi(n/2,a12,1,n/2,1,n/2,a,1,n/2,n/2+1,n);
    fuzhi(n/2,a21,1,n/2,1,n/2,a,n/2+1,n,1,n/2);
    fuzhi(n/2,a22,1,n/2,1,n/2,a,n/2+1,n,n/2+1,n);
    fuzhi(n/2,b11,1,n/2,1,n/2,b,1,n/2,1,n/2);
    fuzhi(n/2,b12,1,n/2,1,n/2,b,1,n/2,n/2+1,n);
    fuzhi(n/2,b21,1,n/2,1,n/2,b,n/2+1,n,1,n/2);
    fuzhi(n/2,b22,1,n/2,1,n/2,b,n/2+1,n,n/2+1,n);
    search(n/2,p1,a11,b11);
    search(n/2,p2,a12,b21);
    search(n/2,p3,a11,b12);
    search(n/2,p4,a12,b22);
    search(n/2,p5,a21,b11);
    search(n/2,p6,a22,b21);
    search(n/2,p7,a22,b22);
    search(n/2,p8,a21,b12);
    juplu(n/2,c11,p1,p2);
    juplu(n/2,c12,p3,p4);
    juplu(n/2,c21,p5,p6);
    juplu(n/2,c22,p7,p8);
    fuzhi(n/2,c,1,n/2,1,n/2,c11,1,n/2,1,n/2);
    fuzhi(n/2,c,1,n/2,n/2+1,n,c12,1,n/2,1,n/2);
    fuzhi(n/2,c,n/2+1,n,1,n/2,c21,1,n/2,1,n/2);
    fuzhi(n/2,c,n/2+1,n,n/2+1,n,c22,1,n/2,1,n/2);
}
int main()
{
    int a[50][50],b[50][50],c[50][50];
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    cin>>a[i][j];
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    cin>>b[i][j];
    search(n,c,a,b);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n-1; j++)
        cout<<c[i][j]<<' ';
        cout<<c[i][n]<<endl;
    }
    search(n,c,b,a);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n-1; j++)
        cout<<c[i][j]<<' ';
        cout<<c[i][n]<<endl;
    }
    return 0;
}
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        c[i][j]=a[i][j]+b[i][j];
    }
}

void fuzhi(int n,int c[][50],int cr1,int cr2,int cl1,int cl2,int a[][50],int ar1,int ar2,int al1,int al2)
{
    int ar,cr,al,cl;
    for (int i=1; i<=n; i++)
    {
        cr=cr1+i-1; ar=ar1+i-1;
        for (int j=1; j<=n; j++)
        {
            cl=cl1+j-1; al=al1+j-1;
            c[cr][cl]=a[ar][al];
        }
    }
}
void search(int n,int c[][50],int a[][50],int b[][50])
{
    if (n==1)
    {
        c[1][1]=a[1][1]*b[1][1];
        return;
    }
    int a11[50][50],a12[50][50],a21[50][50],a22[50][50],b11[50][50],b12[50][50],b21[50][50],b22[50][50];
    int p1[50][50],p2[50][50],p3[50][50],p4[50][50],p5[50][50],p6[50][50],p7[50][50],p8[50][50];
    int c11[50][50],c12[50][50],c21[50][50],c22[50][50];
    fuzhi(n/2,a11,1,n/2,1,n/2,a,1,n/2,1,n/2);
    fuzhi(n/2,a12,1,n/2,1,n/2,a,1,n/2,n/2+1,n);
    fuzhi(n/2,a21,1,n/2,1,n/2,a,n/2+1,n,1,n/2);
    fuzhi(n/2,a22,1,n/2,1,n/2,a,n/2+1,n,n/2+1,n);
    fuzhi(n/2,b11,1,n/2,1,n/2,b,1,n/2,1,n/2);
    fuzhi(n/2,b12,1,n/2,1,n/2,b,1,n/2,n/2+1,n);
    fuzhi(n/2,b21,1,n/2,1,n/2,b,n/2+1,n,1,n/2);
    fuzhi(n/2,b22,1,n/2,1,n/2,b,n/2+1,n,n/2+1,n);
    search(n/2,p1,a11,b11);
    search(n/2,p2,a12,b21);
    search(n/2,p3,a11,b12);
    search(n/2,p4,a12,b22);
    search(n/2,p5,a21,b11);
    search(n/2,p6,a22,b21);
    search(n/2,p7,a22,b22);
    search(n/2,p8,a21,b12);
    juplu(n/2,c11,p1,p2);
    juplu(n/2,c12,p3,p4);
    juplu(n/2,c21,p5,p6);
    juplu(n/2,c22,p7,p8);
    fuzhi(n/2,c,1,n/2,1,n/2,c11,1,n/2,1,n/2);
    fuzhi(n/2,c,1,n/2,n/2+1,n,c12,1,n/2,1,n/2);
    fuzhi(n/2,c,n/2+1,n,1,n/2,c21,1,n/2,1,n/2);
    fuzhi(n/2,c,n/2+1,n,n/2+1,n,c22,1,n/2,1,n/2);
}
int main()
{
    int a[50][50],b[50][50],c[50][50];
    int n;
    fin>>n;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    fin>>a[i][j];
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    fin>>b[i][j];
    search(n,c,a,b);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n-1; j++)
        fout<<c[i][j]<<' ';
        fout<<c[i][n]<<endl;
    }
    search(n,c,b,a);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n-1; j++)
        fout<<c[i][j]<<' ';
        fout<<c[i][n]<<endl;
    }
    return 0;
}
