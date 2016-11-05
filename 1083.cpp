#include<cstdio>

typedef struct
{
    double x1,x2,y1,y2;
} node;

const double  zero=0.0000000000001;
bool exchange(node data1,node data2)
{
    double fx=(data2.y1-data1.y1)*(data1.x2-data1.x1)-(data2.x1-data1.x1)*(data1.y2-data1.y1);
    double fy=(data2.y2-data1.y1)*(data1.x2-data1.x1)-(data2.x2-data1.x1)*(data1.y2-data1.y1);
    if ((fx<=zero&&fx>=-zero)&&(data2.x1>=data1.x1&&data2.x1<=data1.x2||data2.x1<=data1.x1&&data2.x1>=data1.x2))
    return 1;
    if ((fy<=zero&&fx>=-zero)&&(data2.x2>=data1.x1&&data2.x2<=data1.x2||data2.x2<=data1.x1&&data2.x2>=data1.x2))
    return 1;
    return fx*fy<0;
}
int main()
{
    int G;   // the input cases
    int N;   // the number of stick
    int ans[100],num=0;
    node data[100];
    scanf("%d",&G);
    for (int p = 0; p < G; p++)
    {
        scanf("%d",&N);
        for (int i = 0; i < N; i++)
        {
            scanf("%lf%lf%lf%lf",&data[i].x1,&data[i].y1,&data[i].x2,&data[i].y2);
        }
        num=0;
        for (int i = 0; i < N; i++)
        {
            bool o=true;
            for (int j = i+1; j < N; j++)
            {
                if (exchange(data[i],data[j])&&exchange(data[j],data[i]))
                {
                    o=false; break;
                }
            }
            if (o)
            {
                ans[num]=i+1;
                num++;
            }
        }
        printf("%d",ans[0]);
        for (int i=1; i<num; i++)
        printf(" %d",ans[i]);
        if (p<G-1) printf("\n");
    }
    return 0;
}
