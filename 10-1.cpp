#include <cstdio>

int main()
{
    int N,Q,T,C,M;
    while (scanf("%d%d",&N,&Q) != EOF)
    {
        int flag = false;
        for (int i = 0; i < N; i ++){
            scanf("%d",&T);
            scanf("%d",&C);
            if (C == 1) flag = true;
        }
        for (int i=1; i<=Q; i++)
        {
            scanf("%d",&M);
            if (M <= 0)
            {
                printf("NO\n");
                continue;
            }
            else
            {
                if (flag) printf("YES\n");
                else
                {
                    if (M%2 == 0) printf("YES\n");
                    else printf("NO\n");
                }
            }
        }
    }
    return 0;
}
