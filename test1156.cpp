#include<fstream>
using namespace std;
ofstream fout("1156_5.in");
int main()
{
    fout << '(';
    fout << '(';
    fout << '{';
    for (int i = 0; i < 50000; i ++)
    fout << '(';
    for (int i = 0; i < 50000; i ++)
    fout << '[';
    for (int i = 0; i < 50000; i ++)
    fout << '{';
    for (int i = 0; i < 50000; i ++)
    fout << '(';
    for (int i = 0; i < 50000; i ++)
    fout << ')';
    for (int i = 0; i < 50000; i ++)
    fout << '{';
    for (int i = 0; i < 50000; i ++)
    fout << '}';
    for (int i = 0; i < 50000; i ++)
    fout << '}';
    for (int i = 0; i < 50000; i ++)
    fout << ']';
    for (int i = 0; i < 50000; i ++)
    fout << ')';
    fout << '}';
    fout << ')';
    fout << "((((((";
    fout << "))))))";
    fout << ")";
    fout << '[';
}
