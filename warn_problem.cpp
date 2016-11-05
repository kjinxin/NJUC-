#include<cstdio>
#include<cstring>
const int dx[4]={-1,0,0,1};
const int dy[4]={0,-1,1,0};
struct node
{
    int x,y;
};
int map[20][20];
int hash[65];
node a[65];
int ans;
void search(int x,int y,int up,int now)
{
    if (now>ans) ans=now;
    if (now==up)
    {
        printf("%d:%d",a[0].x,a[0].y);
        for (int i=1; i<now; i++)
        {
            printf(" %d:%d",a[i].x,a[i].y);
        }
        printf("\n");
    }
    int x1,y1;
    for (int i=0; i<4; i++)
    {
        x1=x+dx[i]; y1=y+dy[i];
        if (x1>-1&&x1<8&&y1>-1&&y1<8)
        if (hash[map[x1][y1]]==0)
        {
            a[now].x=x1; a[now].y=y1;
            hash[map[x1][y1]]=1;
            search(x1,y1,up,now+1);
            hash[map[x1][y1]]=0;
        }
    }
    return;
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int p=0; p<t; p++)
    {
        memset(hash,0,sizeof(hash));
        memset(a,0,sizeof(a));
        int x,y,up=65; ans=0;
        for (int i=0; i<8; i++)
        for (int j=0; j<8; j++)
        {
            scanf("%d",&map[i][j]);
        }
        scanf("%d%d",&x,&y); a[0].x=x; a[0].y=y;
        hash[map[x][y]]=1;
        search(x,y,65,1);
        printf("%d\n",ans);
        up=ans;
        search(x,y,up,1);
    }
    return 0;
}
