#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("1157_4.in");
int main()
{
    string str;
    long long total,top,i;
    while(fin>>str)
    {
        total=top=0;
        for(i=0;i<str.length();i++)
        {
            switch(str[i])
            {
            case '(':top++;break;
            case ')':if(top!=0)total+=top;break;
            default:break;
            }
            cout<<total<<endl;
        }
        printf("%d\n",total);
    }
    return 0;
}
