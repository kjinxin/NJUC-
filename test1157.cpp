#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
ofstream fout("1157_5.in");

unsigned long ulrand(void) {
    return (
     (((unsigned long)rand()<<24)&0xFF000000ul)
    |(((unsigned long)rand()<<12)&0x00FFF000ul)
    |(((unsigned long)rand()    )&0x00000FFFul));
}
int main()
{
    srand( (unsigned)time( NULL ) );
    for (int p = 0; p < 500000; p ++)
    {
        fout << '(';
    }
    for (int i = 0; i < 500000; i ++)
        fout << ')';
    fout<< endl;
}
