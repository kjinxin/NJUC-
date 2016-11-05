#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
ofstream fout("1158_4.in");

unsigned long ulrand(void) {
    return (
     (((unsigned long)rand()<<24)&0xFF000000ul)
    |(((unsigned long)rand()<<12)&0x00FFF000ul)
    |(((unsigned long)rand()    )&0x00000FFFul));
}
int main()
{
    srand( (unsigned)time( NULL ) );
    for (int i = 0; i < 1000000; i ++)
    {
        fout << ulrand() % 10000000<< ' ';
    }
}
