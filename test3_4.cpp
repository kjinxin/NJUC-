#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
long long max1(long long a, long long b)
{
    if (a > b) return b;
    else return a;
}
long long f[60][60];
long long w[60];
int N;
int main()
{
    memset(f, 0, sizeof(f));
    memset(w, 0, sizeof(w));
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++)
        scanf("%ld", &w[i]);

    for (int i = N - 2; i > 0; i --)
        for (int j = i + 2; j < N + 1; j ++)
        {
            for (int k = i + 1; k < j; k ++)
            {
                if (f[i][j] == 0)
                    f[i][j] = f[i][k] + f[k][j] + w[i]* w[j] * w[k];
                else
                    f[i][j] = max1(f[i][j], f[i][k] + f[k][j] + w[i]* w[j] * w[k]);
            }
        }
    printf("%lld\n", f[1][N]);
    return 0;
}
