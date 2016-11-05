#include<cstdio>

typedef struct
{
   int stime,pos,ftime;
} ship;
int main()
{
    int K,m,n,t,ctime,cstate,num1,num2,num;
    ship data[300];
    scanf("%d",&K);  // K cases
    for (int p=0; p<K; p++)
    {
        // the input data
        num1=0; num2=0;
        scanf("%d%d%d",&m,&n,&t);
        for (int i=0; i<m; i++)
        {
            scanf("%d%d",&data[i].stime,&data[i].pos);
        }
        data[m].stime==100000000;
        ctime=0;   //record the current time
        cstate=0;  //record the current state that whether the ship is in the north or sourth
        // do until all the ship has been transport to the opposite river
        while (num1<m||num2<m)
        {
            while (num1<m&&data[num1].pos==1) num1++;  // find the first ship in the north of the river
            while (num2<m&&data[num2].pos==0) num2++;  // find the first ship in the sourth of the river
            // waiting until a ship comes
            if (data[num1].stime>ctime&&data[num2].stime>ctime)
            {
                ctime=(data[num1].stime<data[num2].stime)?data[num1].stime:data[num2].stime;
            }
            // transport people in the north of the river
            num=0;
            if (cstate==0)
            {
                while (num1<m&&data[num1].stime<=ctime)
                {
                    if (data[num1].pos==0)
                    {
                        num++;
                        data[num1].ftime=ctime+t;
                    }
                    num1++;
                    if (num>=n) break;
                }
                ctime+=t; cstate=1;
            }
            // transport people in the sourth of the river
            else
            {
                while (num2<m&&data[num2].stime<=ctime)
                {
                    if (data[num2].pos==1)
                    {
                        num++;
                        data[num2].ftime=ctime+t;
                    }
                    num2++;
                    if (num>=n) break;
                }
                ctime+=t; cstate=0;
            }
        }
        for (int i=0; i<m; i++)
        printf("%d %d\n",data[i].ftime,data[i].ftime-data[i].stime-t);
        if (p<K-1) printf("\n");
    }
    return 0;
}
