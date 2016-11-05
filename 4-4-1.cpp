#include<iostream>
using namespace std;
int dfn[10010],low[10010],time,C,s[10010],S[10010],top;     bool in[10010];
struct LIST
{
    int v;  LIST *next;
};

LIST *head[10010],*rear[10010],*head1[10010],*rear1[10010];

int chudu[10010];

void tarjan(int v)      /*tarjan求图的强连通分量*/
{
    dfn[v]=low[v]=++time;
    S[top++]=v;
    in[v]=true;
    for(LIST *p=head[v];p!=NULL;p=p->next)
        if(!dfn[p->v])
        {
            tarjan(p->v);
            if(low[p->v]<low[v])
                low[v]=low[p->v];
        }
        else if(in[p->v]&&low[p->v]<low[v])
            low[v]=low[p->v];

    if(low[v]==dfn[v])
    {
        C++;
        do
        {
            v=S[--top];
            in[v]=false;
            s[v]=C;             /*缩图，标记属于同一强连通分量的点*/
        }while(low[v]!=dfn[v]);
    }
}


int main()
{
    int n,m,i,a,b;
    while(cin>>n>>m)
    {
        memset(head,0,sizeof(int)*10010);
        memset(rear,0,sizeof(int)*10010);
        memset(s,0,sizeof(int)*10010);
        top=0;
        for(i=0;i<m;i++)         /*邻接表存储关系图*/
        {
            scanf("%d%d",&a,&b);
            if(rear[a]!=NULL)
            {
                rear[a]->next=new LIST;
                rear[a]=rear[a]->next;
            }
            else
                head[a]=rear[a]=new LIST;
            rear[a]->next=NULL;
            rear[a]->v=b;
        }
        time=0; C=0;
        memset(dfn,0,sizeof(int)*10010);
        memset(low,0,sizeof(int)*10010);
        memset(in,0,sizeof(bool));
        for(i=1;i<=n;i++)
            if(!dfn[i])
                tarjan(i);
        if(C==1)                /*如果只有一个强连通分量，则输出n*/
        {
            cout<<n<<endl;
            continue;
        }

        memset(chudu,0,sizeof(chudu));
        memset(head1,0,sizeof(int)*10010);
        memset(rear1,0,sizeof(int)*10010);
        for(i=1;i<=n;i++)                        /*计算缩图后每个点的出度*/
            for(LIST *p=head[i];p!=NULL;p=p->next)
                {
                if(s[i]!=s[p->v])
                    {
                     chudu[s[i]]=1;
                        if(rear1[s[i]]!=NULL)
                     {
                            rear1[s[i]]->next=new LIST;
                         rear1[s[i]]=rear1[s[i]]->next;
                     }
                     else
                     head1[s[i]]=rear1[s[i]]=new LIST;
                     rear1[s[i]]->next=NULL;
                     rear1[s[i]]->v=s[p->v];
                    }
                }
    return 0;

}
