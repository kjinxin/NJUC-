#include<cstdio>
#include<cstring>
int main()
{
    int N,limit,map[10][10],dp[10][10][1008];
    scanf("%d",&N);
    for (int p=0; p<N; p++)
    {
        scanf("%d",&limit);
        for (int i=1; i<=8; i++)
        for (int j=1; j<=8; j++)
            scanf("%d",&map[i][j]);
        memset(dp,0,sizeof(dp));
        for(int i=8; i>=1; i--)
        for(int j=8; j>=1; j--)
        for(int k=0; k<=limit; k++)
        {
            if(k>=map[i][j])
            {
                int tmp=0;
                tmp=(i!=8 && dp[i+1][j][k-map[i][j]]>tmp)?dp[i+1][j][k-map[i][j]]:tmp;
                tmp=(j!=8 && dp[i][j+1][k-map[i][j]]>tmp)?dp[i][j+1][k-map[i][j]]:tmp;
                dp[i][j][k]=(tmp==0 && !(i==8 && j==8))?0:tmp+map[i][j];
            }
        }
        if(dp[1][1][limit]!=0)
            printf("%d\n",dp[1][1][limit]);
        else
            printf("-1\n");
    }
    return 0;
}
