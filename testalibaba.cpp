#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>


using namespace std;
ofstream fout("1127_5.in");

unsigned long ulrand(void) {
    return (
     (((unsigned long)rand()<<24)&0xFF000000ul)
    |(((unsigned long)rand()<<12)&0x00FFF000ul)
    |(((unsigned long)rand()    )&0x00000FFFul));
}
int main()
{
    srand( (unsigned)time( NULL ) );
    int n = 10000000;
    int *p = new int[n + 1];
    int point = 1, data = 0;
    while (point <= n)
    {
        data = ulrand() % n + 1;
        if (p[data] != data)
        {
            p[data] = data; fout << data << " ";
        }
        while(point < n + 1 && p[point] == point) point ++;
    }
}
