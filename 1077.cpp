#include<cstdio>
#include<cstring>

void search(int t,int &count,int n,int a[],int b[],int hash[])
{
    if (t==n)
    {
        count++;
        return;
    }
    for (int i=1; i<=n; i++)
    {
        if ((hash[i]==0)&&((b[t-1]>i)==(a[t-1]>a[t])))
        {
            hash[i]=1;
            b[t]=i;
            search(t+1,count,n,a,b,hash);
            hash[i]=0;
        }
    }
}
int main()
{
    int n,N,count;
    scanf("%d",&N);
    int a[15],hash[15],b[15];
    for (int p=0; p<N; p++)
    {
        scanf("%d",&n);
        memset(hash,0,sizeof(hash));
        memset(b,0,sizeof(b));
        for (int i=0; i<n; i++)
        scanf("%d",&a[i]);
        count=0;
        for (int i=1; i<=n; i++)
        {
            hash[i]=1;
            b[0]=i;
            search(1,count,n,a,b,hash);
            hash[i]=0;
        }
        printf("%d\n",count-1);
    }
    return 0;
}
