#include<fstream>
#include<cmath>
using namespace std;
ifstream fin("test2.in");
ofstream fout ("test2.out");
bool o;
int gcd(int x,int y)
{
    if (x % y==0) return y;
    else return gcd(y,x % y);
}
void write(int x,int y)
{
    if (((x<0)&&(y>0))||((x>0)&&(y<0)))
    {
        fout<<'-';
    }
    if (x<0) x=-x;
    if (y<0) y=-y;
    int z=gcd(x,y);
    if (y/z>1) fout<<x/z<<'/'<<y/z;
    else fout<<x/z;
}
int main()
{
    int x1,y1,x2,y2;
    int x,y;
    while (fin>>x1>>y1>>x2>>y2)
    {
        o=false;
        x=x1*y2+x2*y1;
        y=y1*y2;
        write(x,y);
        fout<<' ';
        x=x1*y2-x2*y1;
        if (((x<0)&&(y>0))||((x>0)&&(y<0)))
            o=true;
        write(x,y);
        fout<<' ';
        x=x1*x2;
        y=y1*y2;
        write(x,y);
        fout<<' ';
        x=x1*y2;
        y=y1*x2;
        write(x,y);
        fout<<' ';
        if (o) fout<<"true"; else fout<<"false";
        fout<<endl;
    }
    return 0;
}
