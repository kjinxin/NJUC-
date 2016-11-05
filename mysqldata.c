#include<cstdio>
#include<fstream>
#include<string>
ofstream fout("1.out");
ifstream fin("1.in");
string name[10000]
int main(){
    int num = 0;
    while(fin >> name[num])
    num++;
    fout<<num<<endl;
}
