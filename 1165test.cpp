#include<fstream>
using namespace std;
ofstream fout("1165_2.in");
int main()
{
    fout<< "1000 1000 1000 1000" <<endl;
    for (int i = 1; i < 1000 + 1000 + 1000 + 1000; i ++)
    {
        fout<< i <<endl;
    }
    fout << "-" << 1000 + 2000 + 3000<<endl;
}
