#include<stdio.h>
#include<string.h>
#include<fstream>
using namespace std;
ifstream fin("11.in");
ofstream fout("11.out");
int a[100];
int ans = 0, n;

void searcha(int layer)
{
    if (ans == 1) return;
    if (layer == 0)
    {
        ans = 1;
        for (int i = 1; i < 2 * n; i ++)
            fout<<a[i]<<' ';
        fout<<a[2 * n]<<endl;
    }
    for (int i = 1; i < 2 * n - layer; i ++)
    {
        if (a[i] == 0 && a[i + layer + 1] == 0)
        {
                a[i] = layer;
                a[i + layer + 1] = layer;
                searcha(layer - 1);
                a[i + layer + 1] = 0;
                a[i] = 0;
        }
    }
}
int main()
{
    fin>>n;
    memset(a, 0, sizeof(a));
    if (n * (n + 1) / 2 % 2 == 0)
    {
        searcha(n);
    }
    if (ans == 0) fout<<"No Solution."<<endl;
    return 0;
}
