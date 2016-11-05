#include<cstdio>
#include<cstring>
#include<cmath>
struct node
{
    double x,y;
};
#define max1 1000000000
int n;
node pos[5000];
double map[5000][5000],ans;
bool hash[5000];
int a[5000];


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
    hash[0]=1;
}

void greedy()
{
    double min1=max1;
    int j,top=0;
    for (int p=1; p<n; p++)
    {
        min1=max1;
        for (int i=1; i<n; i++)
        {
            if (hash[i]==0&&map[a[top]][i]<min1)
            {
                min1=map[a[top]][i];
                j=i;
            }
        }
        hash[j]=1;
        top++;
        a[top]=j;
    }
    ans=0;
    for (int i=1; i<n; i++)
    {
        ans+=map[a[i-1]][a[i]];
        printf("%d ",a[i]);
    }
    ans+=map[a[n-1]][a[0]];
    printf("%lf\n",ans);
}
int main()
{
    //freopen("1.out","w",stdout);
    freopen("1_2.in","r",stdin);
    initial_input();//read the input and initialize
    greedy();
    //fclose(stdout);
    fclose(stdin);
    return 0;
}
