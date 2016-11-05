#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
using namespace std;

struct node
{
    int x,y;
};
const int maxm=200;
#define INF (1e40)
int field[maxm];
double mfield[maxm],pofield[maxm];
node pos[maxm];
double dis[maxm][maxm];
int n,nfield=0;

double dist(node a,node b)
{
    double x1=a.x,y1=a.y,x2=b.x,y2=b.y;
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void mark(int i, int m)
{
    if (field[i]!=-1) return;
    field[i]=m;
    for (int j=0; j<n; j++)
    if (dis[i][j]<INF/2)
            mark(j,m);
    return;
}

int main()
{
    scanf("%d\n",&n);
    for (int i=0; i<n; i++)
        scanf("%d%d\n",&pos[i].x,&pos[i].y);
    char c;
    for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
    {
        cin>>c;
        if (i==j)
                dis[i][j]=0;
        else
        if (c=='0')
            dis[i][j]=INF;
        else
            dis[i][j]=dist(pos[i], pos[j]);
    }
    for (int k=0; k<n; k++)
    for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
        if(dis[i][k]+dis[k][j] < dis[i][j])
            dis[i][j] = dis[i][k]+dis[k][j];
    for (int i=0; i<n; i++)
    {
        field[i]=-1; pofield[i]=0; mfield[i]=0;
    }
    for (int i=0; i<n; i++)
    if (field[i]==-1)
        mark(i, nfield++);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            if(pofield[i] < dis[i][j] && dis[i][j] < INF/2)
                pofield[i] = dis[i][j];
        if(pofield[i] > mfield[field[i]])
            mfield[field[i]] = pofield[i];
    }
    double newdiam=INF;
    for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
    {
        if (field[i]==field[j])
            continue;
        double d=pofield[i]+pofield[j]+dist(pos[i], pos[j]);
        if (d<mfield[field[i]])
            d=mfield[field[i]];
        if (d<mfield[field[j]])
            d=mfield[field[j]];
        if(d<newdiam)
            newdiam=d;
    }
    printf("%.6lf\n",newdiam);
    return 0;
}
