#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
ofstream fout("1129_test1.in");

unsigned long ulrand(void) {
    return (
     (((unsigned long)rand()<<24)&0xFF000000ul)
    |(((unsigned long)rand()<<12)&0x00FFF000ul)
    |(((unsigned long)rand()    )&0x00000FFFul));
}
int main()
{
    int j;
    cin >> j;
    cout<<"123"<<endl;
    srand( (unsigned)time( NULL ) );
    int n = 100;
    fout << n << endl;
    for (int p = 0; p < n; p ++)
    {
        fout<<ulrand()%10000000 - 5000000<<" ";
    }
    fout<< endl;
    cout << 123 <<endl;
}
