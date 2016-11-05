#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

ifstream fin("2.txt");
ofstream fout("init_1000_8.txt");
long long a[100], b[100], S0[100], E0[100], I0[100];

unsigned long ulrand(void) {
    return (
     (((unsigned long)rand()<<24)&0xFF000000ul)
    |(((unsigned long)rand()<<12)&0x00FFF000ul)
    |(((unsigned long)rand()    )&0x00000FFFul));
}
int main()
{
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < 50; i ++)
    {
        fin >> a[i];
        sum1 += a[i];
    }
    srand( (unsigned)time( NULL ) );
    for (int i = 0; i < 50; i ++)
    {
        fin >> b[i];
        sum2 += b[i];
        int ll = ulrand() % 10000;
        int rr = ulrand() % 10000;
        S0[i] = b[i] * (1000000 - ll - rr) / 1000000;
        E0[i] = b[i] * ll / 1000000;
        I0[i] = b[i] - S0[i] - E0[i];
    }
    cout<<sum2;
    for (int i = 0; i < 50; i ++)
    fout << S0[i] << " ";
    fout << endl;
    for (int i = 0; i < 50; i ++)
    fout << E0[i] << " ";
    fout << endl;
    for (int i = 0; i < 50; i ++)
    fout << I0[i] << " ";
    fout << endl;
}
