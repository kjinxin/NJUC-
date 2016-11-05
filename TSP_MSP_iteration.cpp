//accurate algrithm
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
struct node
{
    double x,y;
};
#define max1 1000000000
int n;
node pos[5000];
double map[5000][5000];
bool hash[5000];
double a[5000];
int b[10000];
int fa[5000];
double ans;
int top;
int dushu[5000][5000];

void initial_input()
{
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        scanf("%lf%lf",&pos[i].x,&pos[i].y);
    }
    for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
    {
        map[i][j]=sqrt((pos[i].x-pos[j].x)*(pos[i].x-pos[j].x)+(pos[i].y-pos[j].y)*(pos[i].y-pos[j].y));
    }
    memset(hash,0,sizeof(hash));
    memset(a,0,sizeof(a));
    memset(dushu,0,sizeof(dushu));
    hash[0]=1;
}
void MSP()
{
    int min1,t,j;
    top=1;
    for (int i=0; i<n; i++)
    {
        a[i]=map[0][i];
        fa[i]=0;
    }
    ans=0;
    while (top<n)
    {
        min1=max1;
        for (int i=1; i<n; i++)
        {
            if (hash[i]==0&&a[i]<min1)
            {
                t=i;  min1=a[i];
            }
        }
        ans+=min1;
        dushu[fa[t]][t]+=2; dushu[t][fa[t]]+=2;
        hash[t]=1;
        for (int i=1; i<n ;i++)
        if (hash[i]==0&&a[i]>map[t][i])
        {
            a[i]=map[t][i];
            fa[i]=t;
        }
        top++;
    }
    //printf("%lf\n",ans);
    return;
}

void Eulerian(int t)
{
    for (int i=0; i<n; i++)
    {
        if (dushu[t][i]>0)
        {
            dushu[t][i]--; dushu[i][t]--;
            Eulerian(i);
        }
    }
    b[0]++;
    b[b[0]]=t;
}

void output1()
{
    memset(hash,0,sizeof(hash));
    ans=0;
    int j=b[b[0]],top=0,a[5000];
    hash[j]=1;
    a[top]=b[b[0]];
    for (int i=b[0]-1; i>0; i--)
    {
        //printf("%d\n",b[i]);
        if (hash[b[i]]==0)
        {
            ans+=map[j][b[i]];
            //printf("%lf\n",ans);
            hash[j]=1;
            j=b[i];
            top++; a[top]=j;
        }
    }
    ans+=map[j][b[b[0]]];
    printf("%lf\n",ans);
    int x,y;
    srand(time (0));
    for (int p=0; p<5*n*n; p++)
    {
        x=rand()%n;
        y=rand()%n;
        while(x==y) y=rand()%n;
        if (x>y)
        {
            j=x; x=y; y=j;
        }
        if (x==0&&y==n-1) continue;
        if (map[a[(x-1+n)%n]][a[x]]+map[a[y]][a[(y+1)%n]]>map[a[x]][a[(y+1)%n]]+map[a[(x-1+n)%n]][a[y]])
        {
            ans=ans+map[a[x]][a[(y+1)%n]]+map[a[(x-1+n)%n]][a[y]]-map[a[(x-1+n)%n]][a[x]]-map[a[y]][a[(y+1)%n]];

            for (int i=x; i<=(x+y)/2; i++)
            {
                j=a[i]; a[i]=a[y-(i-x)]; a[y-(i-x)]=j;
            }
        }
    }
    printf("%lf\n",ans);
}
int main()
{
    //freopen("1.out","w",stdout);
    freopen("1_2.in","r",stdin);
    initial_input();//read the input and initialize
    MSP();
    memset(b,0,sizeof(b));
    Eulerian(0);
    output1();
    fclose(stdout);
    fclose(stdin);
    return 0;
}
