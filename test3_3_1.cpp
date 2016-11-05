#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MAX 1002
#define INT 0x7fffffff

int w[MAX];
int cost[MAX];
bool vis[MAX];
struct node{
    int w,cost;
}map1[MAX][MAX];
int n,m,a,b,d,p,s,t;

int min1(int a, int b)
{
    if (a < b) return a;
    else return b;
}
void SPFA(){
    for(int i=1; i<=n; i++)
    {
        w[i]=-1; cost[i]=-1; vis[i]=false;
    }
    queue<int> q;
    q.push(s);
    w[s]=0;
    cost[s]=0;
    vis[s]=true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        vis[cur]=false;
        for(int i=1; i<=n; i++)
        {
            if (cur == i) continue;
            if (w[i] == -1 && map1[cur][i].w != -1)
            {
                w[i] = w[cur] + map1[cur][i].w;
                cost[i] = cost[cur]+map1[cur][i].cost;
                if(!vis[i])
                {
                    vis[i]=true;
                    q.push(i);
                }
                continue;
            }
            if(map1[cur][i].w !=-1 && w[i] >= w[cur] + map1[cur][i].w)
            {
                if (w[i] == w[cur] + map1[cur][i].w)
                {
                    if(!vis[i] && cost[i] > cost[cur] + map1[cur][i].cost)
                    {
                        vis[i]=true;
                        q.push(i);
                    }
                    cost[i] = cost[cur] + map1[cur][i].cost;
                }
                else
                {
                    w[i] = w[cur]+map1[cur][i].w;
                    if(!vis[i])
                    {
                        vis[i]=true;
                        q.push(i);
                    }
                    cost[i] = cost[cur] + map1[cur][i].cost;
                }
                if (w[i] < 0) printf("dangerous!\n");
            }
        }
    }
}
int main(){
    freopen("path10.in", "r", stdin);
    freopen("path10.out", "w", stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            map1[i][j].w = -1;
            map1[i][j].cost = -1;
        }
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d%d", &a, &b, &d, &p);
        if (map1[a][b].w != -1 && map1[a][b].w <= d)
        {
            if (map1[a][b].w == d)
            {
                map1[a][b].cost = map1[b][a].cost = min1(map1[a][b].cost, p);
            }
        }
        else
        {
            map1[a][b].w = map1[b][a].w = d;
            map1[a][b].cost = map1[b][a].cost = p;
        }
    }
    s = 1; t = n;
    SPFA();
    printf("%d %d\n", w[n], cost[n]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
