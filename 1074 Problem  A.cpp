#include<cstdio>
#include<cstring>
int dushu[88][88],dushu1[88][88],hash[88];
struct node
{
    int color1,color2;
};
  bool o=true;
node data[44];
int ans[44],b[44],c[44];
void Eulerian(int t,int n)
{
    for (int i=0; i<n; i++)
    {
        if (hash[i]==1) continue;

        if (dushu[t][i]>0)
        {
            dushu[t][i]--; dushu[i][t]--; hash[i]=true;
            Eulerian(i,n);
        }
    }
}
void print1(int b[],int p,int q)
{
    printf("%d",b[1]);
    for (int i=2; i<=b[0]; i++)
    printf(" %d",b[i]);
    if (p==q) return;
    printf("\n");
}
int main()
{
    int T,n;
    scanf("%d",&T);
    for (int p=0; p<T; p++)
    {
        scanf("%d",&n);
        memset(dushu,0,sizeof(dushu));
        memset(dushu1,0,sizeof(dushu1));
        memset(data,0,sizeof(data));
        memset(ans,0,sizeof(ans));
        memset(b,0,sizeof(b));
        memset(hash,0,sizeof(0));
        for (int i=0; i<n; i++)
        {
            scanf("%d%d",&data[i].color1,&data[i].color2);
        }
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (i==j) continue;
                if (data[i].color1==data[j].color1)
                {
                    dushu[2*i][2*j]++;
                }
                if (data[i].color1==data[j].color2)
                {
                    dushu[2*i][2*j+1]++;
                }
                if (data[i].color2==data[j].color1)
                {
                    dushu[2*i+1][2*j]++;
                }
                if (data[i].color2==data[j].color2)
                {
                    dushu[2*i+1][2*j+1]++;
                }
            }
            dushu[2*i][2*i+1]++; dushu[2*i+1][2*i]++;
        }
        for (int i=0; i<2*n; i++)
        for (int j=0; j<2*n; j++)
        dushu1[i][j]=dushu[i][j];
        hash[0]=1;
        o=false;
        hash[0]=1;
        Eulerian(0,2*n);
        b[0]++;
        b[b[0]]=ans[ans[0]]/2+1;
        for (int i=ans[0]-1; i>0; i--)
        {
            if (ans[i]/2!=ans[i+1]/2)
            {
                b[0]++;
                b[b[0]]=ans[i]/2+1;
            }
        }
        memset(ans,0,sizeof(ans));
        memset(c,0,sizeof(c));
        for (int i=0; i<2*n; i++)
        for (int j=0; j<2*n; j++)
        dushu[i][j]=dushu1[i][j];
        memset(hash,0,sizeof(hash));
        Eulerian(1,2*n);
        c[0]++;
        c[c[0]]=ans[ans[0]]/2+1;
        for (int i=ans[0]-1; i>0; i--)
        {
            if (ans[i]/2!=ans[i+1]/2)
            {
                c[0]++;
                c[c[0]]=ans[i]/2+1;
            }
        }
        if (b[0]!=n+1)
        {
            printf("%d",-1);
            if (p==T-1) continue;
            printf("\n");
            continue;
        }
        for (int i=1; i<=b[0]; i++)
        {
            if (b[i]<c[i]) break;
            if (c[i]<b[i])
            {
                o=false; break;
            }
        }
        //if (o)
        //{
            print1(b,p,T-1);
        //}
        //else
            print1(c,p,T-1);
    }
    return 0;
}
