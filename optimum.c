#include<stdio.h>
#include<math.h>


int *calculate(int *a, int* b)
{
    int x, y, z;
    x = a[0] + b[0];
    y = ((a[1] > x)?a[1]:x) + b[1];
    z = ((a[2] > y)?a[2]:y)+ b[2];
    a[0] = x; a[1] = y; a[2] = z;
    return a;
}
int main()
{
    int a[4][3] = {{13, 15, 20}, {10, 20, 18}, {20, 16, 10}, {8, 10, 15}};
    int t[3];
    int min = 1000;
    int ans[4], i, j ,k, l;
    printf("%d  %d", a[0][0], a[0][1]);
    for (i = 0; i < 4; i ++)
    {
        for (j = 0; j < 4; j ++)
        {
            if (i != j)
                for (k = 0; k < 4; k ++)
                if (k != i && k != j)
                {
                    l = 6 - i - j - k;
                    int *p;
                    t[0] = a[i][0]; t[1] = a[i][1] + t[0]; t[2] = a[i][2] + t[1];
                    p = calculate(t, a[j]);
                    p = calculate(p, a[k]);
                    p = calculate(p, a[l]);
                    printf("%d %d %d %d %d\n", i, j, k, l, p[2]);
                    if (p[2] < min)
                    {
                        min = p[2];
                        ans[0] = i; ans[1] = j; ans[2] = k; ans[3] = l;
                        printf("%d\n", min);
                        printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);

                    }
                }
        }
    }
    printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
    return 0;
}
