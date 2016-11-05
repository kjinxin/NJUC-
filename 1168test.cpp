#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

ofstream fout("1168_5.in");
unsigned long ulrand(void) {
    return (
     (((unsigned long)rand()<<24)&0xFF000000ul)
    |(((unsigned long)rand()<<12)&0x00FFF000ul)
    |(((unsigned long)rand()    )&0x00000FFFul));
}
int main()
{
    srand( (unsigned)time( NULL ) );
    int n = 1000000;
    for (int i = 1; i <= n; i ++)
    {
        fout << i << " ";
        fout << ulrand()%n << " ";
        fout << ulrand()%n <<endl;
    }
}
