#include<iostream>
using namespace std;

int main()
{
    int f[500][500],n,data[1010];
    while (cin>>n)
    {
        for (int i=1; i<=n+1; i++)
        {
            cin>>data[i];
        }
        for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
        f[i][j]=0;
        for (int l=2; l<=n; l++)
            for (int i=1; i<=n-l+1; i++)
            {
                int j=i+l-1;
                f[i][j]=f[i][i]+f[i+1][j]+data[i]*data[i+1]*data[j+1];
                for (int k=i+1; k<j; k++)
                {
                    if (f[i][k]+f[k+1][j]+data[i]*data[k+1]*data[j+1]<f[i][j])
                        f[i][j]=f[i][k]+f[k+1][j]+data[i]*data[k+1]*data[j+1];
                }
            }
        cout<<f[1][n]<<endl;
    }
    return 0;
}
