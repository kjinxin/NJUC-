//accurate algrithm
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
struct node
{
    double x,y;
};
#define max1 1000000000
int n;
node pos[5000];
double map[5000][5000];
bool hash[5000];
double ans=max1,ans_tem=0;

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
    hash[0]=1;
}

void divide_and_conquer(int tem,int num,double ans_tem) // tem is the father point, num is the total points that we have visited
{
    printf("%d\n",tem);
    if (ans_tem>ans) return;
    if (num==n)
    {
        if (ans_tem+map[tem][0]<ans)
        ans=ans_tem+map[tem][0];
        return;
    }
    for (int i=1; i<n; i++)
    {
        if (hash[i]==0)
        {
            ans_tem+=map[tem][i];
            hash[i]=1;
            divide_and_conquer(i,num+1,ans_tem);
            hash[i]=0;
            ans_tem-=map[tem][i];
        }
    }
    return;
}
int main()
{
    //freopen("1.out","w",stdout);
    freopen("1_1.in","r",stdin);
    initial_input();//read the input and initialize
    divide_and_conquer(0,1,ans_tem);
    printf("%lf",ans);
    fclose(stdout);
    fclose(stdin);
    return 0;
}
