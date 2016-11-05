#include<cstdio>
#include<cstring>
int a[70][70],num[70];
int main()
{
    int t;
    scanf("%d",&t);
    for (int p=0; p<t; p++)   //t组测试数据
    {
        int n;
        scanf("%d",&n); //n组表达式
        memset(num,0,sizeof(num)); //计数器清零
        for (int q=0; q<n; q++)
        {
            for (int r=0; r<3; r++)
            {
                scanf("%d",&a[3*q+r][0]);
                for (int i=0; i<3*q; i++) //连边
                {
                    if (a[i][0]!=-a[3*q+r][0])
                    {
                        num[i]++;
                        a[i][num[i]]=3*q+r;
                        num[3*q+r]++;
                        a[3*q+r][num[3*q+r]]=i;
                    }
                }
            }
        }
        printf("%d %d\n",n*3,n);
        for (int i=0; i<3*n; i++)
        {
            printf("%d",i);
            for (int j=1; j<=num[i]; j++)
            {
                printf(" %d",a[i][j]);
            }
            if (p!=t-1||i!=3*n-1) printf("\n");
        }
        if (p!=t-1) printf("\n");
    }
    return 0;
}
