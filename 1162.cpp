#include<stdio.h>
#include<string.h>
int a[160], v[100];
int ans = 0, n;

void searcha(int t)
{
    if (ans == 1) return;
    if (t > 2 * n)
    {
        ans = 1;
        for (int i = 1; i < 2 * n; i ++)
            printf("%d ", a[i], v[i]);
        printf("%d\n", a[2 * n]);
    }
    if (a[t] != 0)
    {
        searcha(t + 1);
        return;
    }
    for (int i = n; i >= 1; --i )
    {
        if (v[i] != 0) continue;
        if (t + i + 1 <= 2 * n && a[t + i + 1] == 0)
        {
                v[i] = 1;
                a[t] = i;
                a[t + i + 1] = i;
                searcha(t + 1);
                if (ans == 1) return;
                a[t + i + 1] = 0;
                a[t] = 0;
                v[i] = 0;
        }
    }
}
int main()
{
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(v, 0, sizeof(v));
    if (n * (n + 1) / 2 % 2 == 0)
    {
        searcha(1);
    }
    if (ans == 0) printf("No Solution.\n");
    return 0;
}
