#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream fin("jinxin.txt");
ofstream fout("2.txt");
int main()
{
    string st;
    int a[20];
    int t=0;
    while(fin>>st)
    {
        if (st[0]=='1')
        {
            if (t%18!=0)
            {
                fout<<"fault fault fault"<<endl;
                break;
            }
            continue;
        }
        for (int i=0; i<20; i++)
        a[i]=0;
        for (int i=0; i<st.size(); i++)
        {
            a[st[i]-'A'+1]=1;
        }
        int num=0;
        int h=t%18;
        switch (h)
        {
            case 0: num=2; break;
            case 1: num=5; break;
            case 2: num=9; break;
            case 3: num=6; break;
            case 4: num=12; break;
            case 5: num=4; break;
            case 6: num=8; break;
            case 7: num=5; break;
            case 8: num=9; break;
            case 9: num=5; break;
            case 10: num=7; break;
            case 11: num=7; break;
            case 12: num=5; break;
            case 13: num=4; break;
            case 14: num=4; break;
            case 15: num=4; break;
            case 16: num=5; break;
            case 17: num=6; break;
        }
        for (int i=1; i<=num; i++)
            fout<<a[i]<<' ';
        t++;
        if (t%18==0) fout<<endl;
    }
    fout<<t/18<<endl;
    return 0;
}
