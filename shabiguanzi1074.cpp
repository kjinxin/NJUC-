#include<cstdio>
#include<cstring>
struct node
{
    int u,v;
};
node num[88];
int map[88][88],hash[88],map1[88][88];
int a[88],b[88],c[88];
void Eulerian(int u,int n,int a[])
{
    int v;
    for (int i=1; i<=n; i++)
    {
        if (hash[i]==1) continue;
        v=num[i].u;
        if (u==v)
        {
            v=num[i].v;
            if (map[u][v]>0)
            {
                hash[i]=1;
                map[u][v]--; map[v][u]--;
                Eulerian(v,n,a);
            }
        }
        v=num[i].v;
        if (u==v)
        {
            v=num[i].u;
            if (map[u][v]>0)
            {
                hash[i]=true;
                map[u][v]--; map[v][u]--;
                Eulerian(v,n,a);
            }
        }
    }
    a[0]++;
    a[a[0]]=u;
}

int getpoint(int u,int v,int n)
{
    int t=0;
    for (int i=n; i>0; i--)
    {
        if (num[i].u==u&&num[i].v==v||num[i].u==v&&num[i].v==u)
        {
            t++;
            if (t==map[u][v])
            {
                map[u][v]--; map[v][u]--;
                return i;
            }
        }
    }
    return 0;
}
void change(int b[],int a[],int n)
{
    int t,u;
    for (int i=b[0]; i>1; i--)
    {
        u=getpoint(b[i],b[i-1],n);
        if (i==b[0]) t=u;
        a[0]++;
        a[a[0]]=u;
    }
    a[0]++; a[a[0]]=t;
}
void shuchu(int a[],int p,int q)
{
    printf("%d",a[1]);
    for (int i=2; i<=a[0]; i++)
    printf("% d",a[i]);
    if (p==q) return;
    printf("\n");
}
void copy1(int map[][88],int map1[][88],int max)
{
    for (int i=0; i<=max; i++)
    for (int j=0; j<=max; j++)
    map1[i][j]=map[i][j];
}
int main()
{
    int T;
    int n,u,v;
    scanf("%d",&T);
    for (int p=0; p<T; p++)
    {
        scanf("%d",&n);
        memset(map,0,sizeof(map));
        memset(hash,0,sizeof(hash));
        memset(map1,0,sizeof(map1));
        int max=-1;
        for (int i=0; i<n; i++)
        {
            scanf("%d%d",&num[i+1].u,&num[i+1].v);
            if (num[i+1].u>max) max=num[i+1].u;
            if (num[i+1].v>max) max=num[i+1].v;
            hash[num[i+1].u]++; hash[num[i+1].v]++;
            if (i==0)
            {
                u=num[i+1].u; v=num[i+1].v;
            }
            map[num[i+1].v][num[i+1].u]++;
            map[num[i+1].u][num[i+1].v]++;
        }
        bool o=false;
        for (int i=0; i<=max; i++)
        {
            if (hash[i]%2==1)
            {
                o=true; break;
            }
        }
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        memset(hash,0,sizeof(hash));
        copy1(map,map1,max);
        Eulerian(u,n,c);
        copy1(map1,map,max);
        change(c,a,n);
        copy1(map1,map,max);
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(hash,0,sizeof(hash));
        Eulerian(v,n,c);
        copy1(map1,map,max);
        if (c[1]!=c[c[0]]) o=true;
        for (int i=1; i<c[0]; i++)
        if (map[c[i]][c[i+1]]==0)
        {
            o=true; break;
        }
        if (a[0]!=n+1) o=true;
        if (o)
        {
            printf("-1");
            if (p!=T-1) printf("\n");
            continue;
        }
        copy1(map1,map,max);
        change(c,b,n);
        o=true;
        for (int i=1; i<=a[0]; i++)
        {
            if (a[i]<b[i]) break;
            if (b[i]<a[i])
            {
                o=false; break;
            }
        }
        if (o)
        shuchu(a,p,T-1);
        else
        shuchu(b,p,T-1);
    }
    return 0;
}
