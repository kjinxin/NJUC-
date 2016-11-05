//**************************two lane symatric origin model no random********************************
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<iostream>
#include<fstream>
using namespace std;

#define max_length 10000
#define steps 50000
#define carl 6
typedef struct {
  int car;
  int vel;
}road_t;
ofstream fout("1.out");
road_t Road1[max_length],Road2[max_length];
int vmax=33;
int dtime=0,otime=0;
int density=500;
int min1(int x, int y)
{
    if (x<y) return x;
    else return y;
}
int outnum=0,ans=0,left1=0,p=100;
void sett(int den,int length)
{
    int pos;
    int o=true;
    int t;
    for (int i=0; i<den; i++)
    {
        o=true;
        t=rand()%2;
        if (t==1)
        {
//******************初始状态随机在第一条车道上产生车辆**************************
            while (o)
            {
                pos=rand()%(length-6)+6;
                for (int j=-5; j<=5; j++)
                if (pos+j<max_length&&Road1[pos+j].car==1)
                {
                    o=false; break;
                }
                if (!o)
                    o=true;
                else
                {
                    Road1[pos].car=1;
                    Road1[pos].vel=rand()%vmax;
                    break;
                }
            }
        }
        else
        {
//****************初始状态在第二条道路上产生车辆******************
            while (o)
            {
                pos=rand()%(length-6)+6;
                for (int j=-5; j<=5; j++)
                if (pos+j<max_length&&Road2[pos+j].car==1)
                {
                    o=false; break;
                }
                if (!o)
                    o=true;
                else
                {
                    Road2[pos].car=1;
                    Road2[pos].vel=rand()%vmax;
                    break;
                }
            }
        }
    }
}
void resett(int &left1, int length)
{
    int pos;
    int o=true;
    int den=left1,t=0,tp;
    for (int i=0; i<den; i++)
    {
        o=true; t=0;
        tp=rand()%2;
        if (tp==1)
        {
//******************在第一条道路上随机补充车辆**********************
            while (o&&t<1000)
            {
                pos=rand()%(length-6)+6;
                for (int j=-5; j<=5; j++)
                if (pos+j<max_length&&Road1[pos+j].car==1)
                {
                    o=false; break;
                }
                if (!o)
                    o=true;
                else
                {
                    Road1[pos].car=1;
                    Road1[pos].vel=rand()%vmax;
                    left1--;
                    break;
                }
                t++;
            }
        }
        else
        {
//******************在第二条道路上随机补充车辆******************************
            while (o&&t<1000)
            {
                pos=rand()%(length-6)+6;
                for (int j=-5; j<=5; j++)
                if (pos+j<max_length&&Road2[pos+j].car==1)
                {
                    o=false; break;
                }
                if (!o)
                    o=true;
                else
                {
                    Road2[pos].car=1;
                    Road2[pos].vel=rand()%vmax;
                    left1--;
                    break;
                }
                t++;
            }
        }
    }
}
void speedupanddown()
{
    bool o=true;
    int k=0;
    if (steps%2==0)
    {
        for (int i=max_length-1; i>0; i--)
        {
            if (Road1[i].car==1)
            {
                Road1[i].vel=min1(Road1[i].vel+1,vmax);
                int len=Road1[i].vel+i+carl;
                if (len>=max_length) len=max_length-1;
                o=true;
                for (int j=i+carl; j<=len; j++)
                {
                    if (Road1[j].car==1)
                    {
                        o=false;
                        k=j;
                        break;
                    }
                }
                if (!o)
                {
                    bool t=true;
                    if (Road1[i].vel>Road1[k].vel)
                    {
                        for (int j=-5; j<=5; j++)
                        {
                            if (j+i>=0&&j+i<max_length&&Road2[j+i].car==1)
                            {
                                t=false; break;
                            }
                        }
                        /*for (int j=i+carl; j<=len; j++)
                        {
                            if (Road2[j].car==1&&Road2[j].vel<Road1[i].vel)
                            {
                                t=false; break;
                            }
                            if (Road2[j].car==1&&Road2[j].vel>=Road1[i].vel)
                            break;
                        }*/
                        if (t)
                        {
                            Road2[i]=Road1[i];
                            Road1[i].car=0;
                            otime++;
                        }
                        else
                        {
                            Road1[i].vel=k-i-carl;
                            dtime++;
                        }
                    }
                }
            }
        }
//**************************道路二**************************
        for (int i=max_length-1; i>0; i--)
        {
            if (Road2[i].car==1)
            {
                Road2[i].vel=min1(Road2[i].vel+1,vmax);
                int len=Road2[i].vel+i+carl;
                if (len>=max_length) len=max_length-1;
                o=true;
                for (int j=i+carl; j<=len; j++)
                {
                    if (Road2[j].car==1)
                    {
                        o=false;
                        k=j;
                        break;
                    }
                }
                if (!o)
                {
                    if (Road2[i].vel>Road2[k].vel)
                    {
                        Road2[i].vel=k-i-carl;
                        dtime++;
                    }
                }
            }
        }
    }
    else
    {
//********************道路二调整速度或超车*****************
       for (int i=max_length-1; i>0; i--)
        {
            if (Road2[i].car==1)
            {
                Road2[i].vel=min1(Road2[i].vel+1,vmax);
                int len=Road2[i].vel+i+carl;
                if (len>=max_length) len=max_length-1;
                o=true;
                for (int j=i+carl; j<=len; j++)
                {
                    if (Road2[j].car==1)
                    {
                        o=false;
                        k=j;
                        break;
                    }
                }
                if (!o)
                {
                    bool t=true;
                    if (Road2[i].vel>Road2[k].vel)
                    {
                        for (int j=-5; j<=5; j++)
                        {
                            if (j+i>=0&&j+i<max_length&&Road1[j+i].car==1)
                            {
                                t=false; break;
                            }
                        }
                        /*for (int j=i+carl; j<=len; j++)
                        {
                            if (Road1[j].car==1&&Road1[j].vel<Road2[i].vel)
                            {
                                t=false; break;
                            }
                            if (Road1[j].car==1&&Road1[j].vel>=Road2[i].vel)
                            break;
                        }*/
                        if (t)
                        {
                            Road1[i]=Road2[i];
                            Road2[i].car=0;
                            otime++;
                        }
                        else
                        {
                            Road2[i].vel=k-i-carl;
                            dtime++;
                        }
                    }
                }

            }
        }

//********************道路一调整速度或超车*************
        for (int i=max_length-1; i>0; i--)
        {
            if (Road1[i].car==1)
            {
                Road1[i].vel=min1(Road1[i].vel+1,vmax);
                int len=Road1[i].vel+i+carl;
                if (len>=max_length) len=max_length-1;
                o=true;
                for (int j=i+carl; j<=len; j++)
                {
                    if (Road1[j].car==1)
                    {
                        o=false;
                        k=j;
                        break;
                    }
                }
                if (!o)
                {
                    if (Road1[i].vel>Road1[k].vel)
                    {
                        Road1[i].vel=k-i-carl;
                        dtime++;
                    }
                }
            }
        }
    }

}

void movement()
{
    for (int i=max_length-1; i>0; i--)
    {
        if (Road1[i].car==1)
        {
            Road1[i].car=0;
            if (Road1[i].vel+i>=max_length)
            {
                outnum++;
            }
            else
            {
                Road1[i+Road1[i].vel].car=1;
                Road1[i+Road1[i].vel].vel=Road1[i].vel;
            }

        }
        if (Road2[i].car==1)
        {
            Road2[i].car=0;
            if (Road2[i].vel+i>=max_length)
            {
                outnum++;
            }
            else
            {
                Road2[i+Road2[i].vel].car=1;
                Road2[i+Road2[i].vel].vel=Road2[i].vel;
            }
        }
    }
}
int main()
{
    srand(time (0));
    for (density=100; density<=1000; density+=100)
    {
        fout<<density<<endl;
        for (vmax=8; vmax<=44; vmax+=3)
        {
            outnum=0; left1=0; dtime=0; otime=0;
            for (int i=0; i<max_length; i++)
            {
                Road1[i].car=0;
                Road1[i].vel=0;
                Road2[i].car=0;
                Road2[i].vel=0;
            }
            sett(density,10000);
            int n=0;
            while (n<=steps)
            {
                left1+=outnum;
                resett(left1,1000);
                /*int j=0;
                for (int i=0; i<max_length; i++)
                {
                    if (Road1[i].car==1) j++;
                    if (Road2[i].car==1) j++;
                }
                fout<<j<<' '<<left1<<' '<<outnum<<' '<<n<<endl;*/
                outnum=0;
                speedupanddown();
                movement();
                ans+=outnum;
                n++;
            }
            fout<<ans/50000.0<<"      "<<dtime<<"      "<<otime<<endl;
            ans=0;
        }
    }
    return 0;
}

