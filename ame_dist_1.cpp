#include<iostream>
#include<cstdio>
#include<cmath>
#include<fstream>
using namespace std;

ifstream fin("la_lo.txt");
ofstream fout("dist.txt");

#define PI                      3.1415926
#define EARTH_RADIUS            6378.137        //地球近似半径

double radian(double d);
double get_distance(double lat1, double lng1, double lat2, double lng2);

// 求弧度
double radian(double d)
{
    return d * PI / 180.0;   //角度1˚ = π / 180
}

//计算距离
double get_distance(double lat1, double lng1, double lat2, double lng2)
{
    double radLat1 = radian(lat1);
    double radLat2 = radian(lat2);
    double a = radLat1 - radLat2;
    double b = radian(lng1) - radian(lng2);

    double dst = 2 * asin((sqrt(pow(sin(a / 2), 2) + cos(radLat1) * cos(radLat2) * pow(sin(b / 2), 2) )));

    dst = dst * EARTH_RADIUS;
    dst= round(dst * 10000) / 10000;
    return dst;
}
int main()
{
    double map[100][2];
    double dist[100][100];
    string name[100];
    for (int i = 0; i < 50; i ++)
    {
        for (int j = 0; j < 2; j ++)
        {
            fin >> map[i][j];
            map[i][j] = map[i][j];
        }
    }
    double LatA, MLonA, LatB, MLonB;
    for (int i = 0; i < 50; i ++)
    {
        for (int j = 0; j < 50; j ++)
        {
            dist[i][j] = get_distance(map[i][0], map[i][1], map[j][0], map[j][1]);
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i < 50; i ++)
    fin>> name [i];
    double ans[100];
    int fa[100];
    int hash[100];
    for (int i = 0; i < 50; i ++)
    {
        fa[i] = -1;
        hash[i] = -1;
    }

    fa[4] = 4;
    ans[4] = 0;
    for (int i = 0; i < 50; i ++)
    {
        ans[i] = dist[4][i];
        fa[i] = 4;
    }

    for (int time = 0; time < 48; time ++)
    {
        int min = 100000000, t = 0;
        for (int i = 0; i < 50; i ++)
        {
            if (hash[i] == -1 && ans[i] < min)
            {
                min = ans[i];
                t = i;
            }
        }
        hash[t] = 0;
        for (int i = 0; i < 50; i ++)
        {
            if (hash[i] == -1 && dist[t][i] < ans[i])
            {
                ans[i] = dist[t][i];
                fa[i] = t;
            }
        }
    }
    double sum = 0;
    for (int i = 0; i < 50; i ++)
    sum += ans[i];
    fout<<sum<<endl;
    for (int i = 0; i < 50; i ++)
    {
        //fout<<i << " " <<fa[i] << " "<<ans[i]<<endl;
        fout<< name[i] << "   " <<name[fa[i]]<<"   "<< ans[i]<< endl;
    }
}
