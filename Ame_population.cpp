#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

ifstream fin("1.txt");
ofstream fout("tri.txt");
int main()
{
    int a[10000];
    string b[10000];
    int t = -1;
    int tt;
    string st1 = "", st2 = "";
    memset(a, 0, sizeof(a));
    while (fin >> st2 >> tt) {
        if (st1 != st2)
        {
            a[++t] = tt;
            b[t] = st2;
            st1 = st2;
        }
        else a[t] += tt;
    }
    for (int i = 0; i < t; i ++)
    fout<< a[i]<< endl;
}
