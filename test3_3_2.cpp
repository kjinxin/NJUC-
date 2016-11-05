#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand( (unsigned)time( NULL ) );
    freopen("path10.in", "w", stdout);
    int n = 1000;
    int m =1000;
    printf("%d %d\n", n, m);
    for (int i = 1; i < n; i ++)
        printf("%d %d %d %d\n", i, i + 1, rand() % 100, rand() % 100);
    int a, b;
    for (int i = 1; i < m - n + 2; i ++)
    {
        a = rand() % n + 1;
        b = rand() % n + 1;
        while (b == a) b = rand() % n + 1;
        printf("%d %d %d %d\n", a, b, rand() % 100, rand() % 100);
    }
    fclose(stdout);
}
