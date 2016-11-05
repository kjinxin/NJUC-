#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("1157_5.in");
ofstream fout("1157_5.out");

int main()
{
    long long ans = 0, leftnum = 0;
    char ch;
    while (fin >> ch)
    {
        if (ch == '(') leftnum ++;
        if (ch == ')') ans += leftnum;
    }
    fout << ans << endl;
}
