#include<cstdio>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
ofstream fout("mysqlout.txt");
ifstream fin("mysqlin.txt");
string name[10000];
int main(){
    int num = 0;
    while(fin >> name[num])
    {
       num++;
       fout<<name[num];
    }

    srand(time(0));
    for (int i = 0; i < 2000; i++)
    {
        int sno = 201206;
        string sname;
        string sgend;
        string snation = "��";
        string smsch = "�º��߼���ѧ";
        string sgrad = "2012";
        string saddr = "����ʡ���Ƹ��к�����";
        string sfana;
        long sfatel = 1509837988 + i;
        string scode = "12345678";
        int exno = 201205;
        string etype;
        string esub;
        int chgra, magra, engra, adgra, infogra, optgra1, optgra2;
        int reqgra1, reqgra2, reqgra3, reqgra4;
        sno = sno * 10000 + i;
        sname = name[rand()%5000];
        int t = rand()%2;
        if (t == 0) sgend = "��";
        else sgend = "Ů";
        sfana = name[rand()%5000];
        exno = exno * 10000 + i;
        t = rand()%2;
        if (t == 0) etype = "��";
        else etype = "��";
        t = rand()%4;
        switch (t){
            case 0:
                esub = "��";
                break;
            case 1:
                esub = "��";
                break;
            case 2:
                esub = "��";
                break;
            case 3:
                esub = "��";
        }
        chgra = rand() % 100 + 60;
        magra = rand() % 100 + 60;
        engra = rand() % 70 + 50;
        adgra = rand() % 30 + 10;
        infogra = rand() % 50 + 50;
        optgra1 = rand() % 70 + 50;
        optgra2 = rand() % 70 + 50;
        reqgra1 = rand() % 50 + 50;
        reqgra2 = rand() % 50 + 50;
        reqgra3 = rand() % 50 + 50;
        reqgra4 = rand() % 50 + 50;
        fout<<"insert into student values(";
        fout<<"\'"<<sno<<"\',";
        fout<<"\'"<<sname<<"\',";
        fout<<"\'"<<sgend<<"\',";
        fout<<"\'"<<snation<<"\',";
        fout<<"\'"<<smsch<<"\',";
        fout<<"\'"<<sgrad<<"\',";
        fout<<"\'"<<saddr<<"\',";
        fout<<"\'"<<sfana<<"\',";
        fout<<"\'"<<sfatel<<"\',";
        fout<<"\'"<<scode<<"\');"<<endl;
        fout<<"insert into exam (exno, sno, etype, esub, chgra, magra, engra, adgra, infogra, optgra1, optgra2, reqgra1, reqgra2, reqgra3, reqgra4)values(";
        fout<<"\'"<<exno<<"\',";
        fout<<"\'"<<sno<<"\',";
        fout<<"\'"<<etype<<"\',";
        fout<<"\'"<<esub<<"\',";
        fout<<chgra<<",";
        fout<<magra<<",";
        fout<<engra<<",";
        fout<<adgra<<",";
        fout<<infogra<<",";
        fout<<optgra1<<",";
        fout<<optgra2<<",";
        fout<<reqgra1<<",";
        fout<<reqgra2<<",";
        fout<<reqgra3<<",";
        fout<<reqgra4<<");"<<endl;

    }

}
