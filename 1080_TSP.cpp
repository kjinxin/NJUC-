//accurate algrithm
#include<cstdio>
#include<cstring>

#define max1 10000000
int n;
int map[50][50];
bool hash[50];
int a[50];
int b[100];
int fa[50];
int top;
int dushu[50][50];

void initial_input()
{
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
    {
        scanf("%d",&map[i][j]);
    }
    memset(hash,0,sizeof(hash));
    memset(a,0,sizeof(a));
    memset(dushu,0,sizeof(dushu));
    hash[0]=1;
}
void MSP()
{
    int min1,t,j;
    top=1;
    for (int i=0; i<n; i++)
    {
        a[i]=map[0][i];
        fa[i]=0;
    }
    while (top<n)
    {
        min1=max1;
        for (int i=1; i<n; i++)
        {
            if (hash[i]==0&&a[i]<min1)
            {
                t=i;  min1=a[i];
            }
        }
        dushu[fa[t]][t]+=1; dushu[t][fa[t]]+=1;
        hash[t]=1;
        for (int i=1; i<n ;i++)
        if (hash[i]==0&&a[i]>map[t][i])
        {
            a[i]=map[t][i];
            fa[i]=t;
        }
        top++;
    }
    return;
}

void dfs(int t)
{
    b[0]++;
    b[b[0]]=t;
    for (int i=0; i<n; i++)
    {
        if (hash[i]==0&&dushu[t][i]>0)
        {
            hash[i]=1;
            dfs(i);
        }
    }
}

void output1()
{
    for (int i=1; i<b[0]; i++)
    printf("%d ",b[i]+1);
    printf("%d\n",b[b[0]]+1);
}
int main()
{
    int k;
    scanf("%d",&k);
    for (int p=0; p<k; p++)
    {
        initial_input();//read the input and initialize
        MSP();
        memset(b,0,sizeof(b));
        memset(hash,0,sizeof(hash));
        hash[0]=1;
        dfs(0);
        output1();
    }
    return 0;
}
