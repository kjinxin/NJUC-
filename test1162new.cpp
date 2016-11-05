#include<stdio.h>
#include<string.h>
#include<fstream>

using namespace std;
ifstream fin("10.in");
ofstream fout("10.out");
int a[200], v[100];
int ans = 0, n;

void searcha(int t)
{
    if (ans == 1) return;
    if (t == 2 * n)
    {
        ans = 1;
        for (int i = 1; i < 2 * n; i ++)
            fout<<a[i]<<' ';
        fout<<a[2 * n]<<endl;
    }
    if (a[t] != 0) searcha(t + 1);
    else
    for (int i = n; i > 0; i --)
    {
        if (v[i] == 0 && t + i + 1 <= 2 * n && a[t] == 0 && a[t + i + 1] == 0)
        {
                v[i] = 1;
                a[t] = i;
                a[t + i + 1] = i;
                searcha(t + 1);
                a[t + i + 1] = 0;
                a[t] = 0;
                v[i] = 0;
        }
    }
}
int main()
{
    fin >>n;
    memset(a, 0, sizeof(a));
    memset(v, 0, sizeof(v));
    if (n * (n + 1) / 2 % 2 == 0)
    {
        searcha(1);
    }
    if (ans == 0) fout<<"No Solution."<<endl;
    return 0;
}
