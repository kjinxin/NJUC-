#include<cstdio>
struct sg{
    int x, y, x1, y1, r;
};

int i, j, n, k, c1, c2;
sg a[1010];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i < k + 1; i ++)
    {
        scanf("%d%d%d", &a[i].r, &a[i].x1, &a[i].y1);
        a[i].x = a[i].r / n;
        if (a[i].r % n > 0) a[i].x ++;
        a[i].y = a[i].r % n;
        if (a[i].y == 0) a[i].y = n;
    }
    for (int i = 1; i < k + 1; i ++)
    {
        c1 = a[i].y1 - a[i].y;
        if (c1 < 0) c1 += n;
        for (int j = i; j < k + 1; j ++)
        if (a[j].x == a[i].x)
        {
            a[j].y += c1;
            if (a[j].y > n) a[j].y -= n;
        }
        c2 = a[i].x1 - a[i].x;
        if (c2 < 0) c2 += n;
        for (int j = i; j < k + 1; j++)
        if (a[j].y == a[i].y)
        {
            a[j].x += c2;
            if (a[j].x > n) a[j].x -= n;
        }
        printf("%d\n", c1 + c2);
    }
    return 0;
}
