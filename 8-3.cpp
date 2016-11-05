#include<iostream>
using namespace std;

int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};

struct node
{
    int x,y;
};
int main()
{
    int t,g[1010][1010],n,m,k,x,y,x1,y1,data[10000],hash[1000][1000];
    node a[1000000];
    cin>>t;
    for (int p=1; p<=t; p++)
    {
        cin>>n>>m>>k;
        for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            g[i][j]=0;
            hash[i][j]=0;
        }
        for (int i=1; i<=k; i++)
        {
            cin>>x>>y;
            g[x+1][y+1]=-1;
        }
        for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            if (g[i][j]!=-1)
            for (int k=1; k<=8; k++)
            {
                x1=i+dx[k]; y1=j+dy[k];
                if (x1>0&&x1<=n&&y1>0&&y1<=m&&g[x1][y1]==-1)
                g[i][j]++;
            }
        }
        int time=0,l=1,r=1;
        int num=0;
        for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            if (hash[i][j]==0&&g[i][j]==0)
            {
                num++;
                l=1; r=1; a[l].x=i; a[l].y=j;
                while (l<=r)
                {
                    for (int k=1; k<=8; k++)
                    {
                        x1=a[l].x+dx[k]; y1=a[l].y+dy[k];
                        if (x1>0&&x1<=n&&y1>0&&y1<=m)
                        {
                            if (g[x1][y1]==0)
                            {
                                r++; a[r].x=x1; a[r].y=y1; time++;
                            }
                            if (g[x1][y1]>0)
                            {
                                data[num]++;
                                time++;
                            }
                        }
                    }
                    l++;
                }
            }
        }
        time=n*m-k-time;
        int time1=0,time2=0;
        for (int i=1; i<=num; i++)
        {
            if (data[i]%2==0) time2++;
            else time1++;
        }
        cout<<"Case #"<<p<<": ";
        if (num==0)
        {
            if (time%2==0) cout<<"Fanglaoshi"<<endl;
            else cout<<"Xiemao"<<endl;
        }
        else
        {
            if(time%2==0)
            {
                    if (time1%2==1)
                    {
                        if (num%2==1)
                        cout<<"Fanglaoshi"<<endl;
                        else
                        cout<<"Xiemao"<<endl;
                    }
                    else
                    {
                        if (num%2==1)
                        cout<<"Xiemao"<<endl;
                        else
                        cout<<"Fanglaoshi"<<endl;
                    }
            }
            else
            {
                    if (time1%2==1)
                    {
                        if (num%2==0)
                        cout<<"Fanglaoshi"<<endl;
                        else
                        cout<<"Xiemao"<<endl;
                    }
                    else
                    {
                        if (num%2==0)
                        cout<<"Xiemao"<<endl;
                        else
                        cout<<"Fanglaoshi"<<endl;
                    }
            }
        }
    }
    return 0;
}
