#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("110.txt");
ofstream fout("kongo.txt");

int num[500];
double d1[500],d2[500],d3[500],d4[500],d5[500];

void printt(double * a)
{
    for (int i = 0; i < 383; i ++)
    fout<< a[i]<<endl;
    fout<<endl;
}
int main()
{
    double he1, he2, he3;
    for (int i = 0; i < 383; i ++)
    {
            fin>>num[i]>>d1[i]>>d2[i]>>d3[i]>>d4[i]>>he1>>d5[i];
            fin>>he2>>he3;
            cout<<num[i]<<endl;
    }
    printt(d5);
}


