#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

ifstream fin("2.txt");
ofstream fout("ame_tripop.txt");
long long a[100], b[100], c[60][60];
int main()
{
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < 50; i ++)
    {
        fin >> a[i];
        sum1 += a[i];
    }
    for (int i = 0; i < 50; i ++)
    {
        fin >> b[i];
        sum2 += b[i];
    }
    memset(c, 0, sizeof(c));
    for (int i = 0; i < 50; i ++)
    for (int j = 0; j < 50; j ++)
    {
        if (i != j)
        {
            c[i][j] = a[i] * a[j] / (sum1 - a[i]);
        }
    }
    for (int i = 0; i < 50; i ++)
    for (int j = i + 1; j < 50; j ++)
    {
        int tt1 = c[i][j];
        int tt2 = c[j][i];
        if (tt1 < tt2) tt1 = tt2;
        c[i][j] = tt1; c[j][i] = tt1;
    }
    for (int i = 0; i < 50; i ++)
    {
        for (int j = 0; j < 50; j ++)
        {
            fout << c[i][j] << " ";
        }
        fout<<endl;
    }
}
