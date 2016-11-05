#include<stdio.h>

int n, m;
int fa[30010];
int num[30010];

int findfa(int a)
{
    if (fa[a] == a) return a;
    fa[a] = findfa(fa[a]);
    return fa[a];
}
int main()
{
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 0; i <= n; i ++)
    {
        fa[i] = i;
        num[i] = 1;
    }
    int fa1, fa2;
    for (int i = 0; i < m; i ++)
    {
        scanf("%d%d", &a, &b);
        fa1 = findfa(a);
        fa2 = findfa(b);
        if (fa1 != fa2)
        {
            fa[fa2] = fa1;
            num[fa1] += num[fa2];
        }
    }
    int maxnum = -1;
    for (int i = 1; i <= n; i ++)
        if (num[i] > maxnum) maxnum = num[i];
    printf("%d\n", maxnum);
    return 0;
}
