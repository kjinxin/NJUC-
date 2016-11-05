
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
ofstream fout("1128_3.in");
int main()
{
    srand( (unsigned)time( NULL ) );
    fout<< 2 << " " << 4 << " " << 6 <<endl;
    for (int p = 0; p < 20000; p ++)
    {
        int t = rand() % 3;
        if (t == 0) fout<<"R";
        if (t == 1) fout<<"Y";
        if (t == 2) fout<<"B";
    }
}
