#include<cstdio>
#include<cstring>
struct node{
    int x;
    int next;
};
int T;
int N, M;
int a[100002][3];
node hash[200002];
int orginal[100002];
int ans[100002];
int orsig, k;
int numk[100002];
int init = 100002;

void search(int sig)
{
    if (hash[sig].x != -1)
    {
        //printf("jinxin\n");
        ans[hash[sig].x] ++;
        for (int i = 0; i < numk[hash[sig].x]; i ++)
        search(a[hash[sig].x][i]);
        int next = sig;
        while(hash[next].next != -1)
        {
            next = hash[next].next;
            ans[hash[next].x] ++;
            for (int i = 0; i < numk[hash[next].x]; i ++)
            search(a[hash[next].x][i]);
        }
    }
}
int main()
{
    scanf("%d", &T);
    for (int p = 0; p < T; p ++)
    {
        memset(ans, 0 , sizeof(ans));
        memset(numk, 0, sizeof(numk));
        memset(a, 0, sizeof(a));
        memset(orginal, 0, sizeof(orginal));
        for (int i = 0; i < 200002; i ++)
        {
            hash[i].x = -1; hash[i].next = -1;
        }
        init = 100002;
        scanf("%d%d", &N, &M);
        for (int i = 0; i < M; i ++)
        scanf("%d", &orginal[i]);

        for (int i = 0; i < N; i ++)
        {
            scanf("%d%d", &orsig, &numk[i]);
            int next = orsig;
            if (hash[orsig].x == -1)
            {
                hash[orsig].x = i;
            }
            else
            {
                while (hash[next].next != -1)
                {
                    next = hash[next].next;
                }
                hash[next].next = init;
                hash[init++].x = i;
            }
            for (int j = 0; j < numk[i] ; j ++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < M; i ++)
        {
            search(orginal[i]);
        }
        for (int i = 0; i < N; i ++)
        printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}
