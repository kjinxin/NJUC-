#include<cstdio>
#include<cstring>

typedef struct{
        int used,last,next;
} node;

void search(int num1,int num4,char ans[][40],int num2,char datach[],int num3,node try_tree[][62])
{
    if (datach[num2]=='\0')
    {
        printf("%s",ans[0]);
        for (int i=1; i<num1; i++)
        printf(" %s",ans[i]);
        printf('\n');
        return;
    }
    if (try_tree[num3][datach[num2]-'A'].used==1)
    {
        ans[num1][num4]=datach[num2];
        if (try_tree[num3][datach[num2]-'A'].last==1)
        {
            ans[num1][num4+1]='\n'; numn[num1]=num4;
            search(num1+1,0,ans,num2+1,datach,0,try_tree);
        }
        if (datach[num2+1]!='\0') search(num1,num4+1,ans,num2+1,datach,try_tree[num3][datach[num2]-'A'].next,try_tree);
    }
    return;
}
int main()
{
    int G;
    node try_tree[1000][62];
    char ch[40];
    char datach[2000];
    char ans[250][40];
    int numn[250];
    scanf("%d",&G);
    for (int p=0; p<G; p++)
    {
        int n,num=0; fnum=0;
        scanf("%d",&n);
        memset(try_tree,0,sizeof(try_tree));
        memset(numn,0,sizeof(numn));
        memset(Fnum,0,sizeof(Fnum));
        memset(fans,0,sizeof(fans));
        for (int i=0; i<n; i++)
        {
            scanf("%s",ch);
            int j=0,t=0;
            while (ch[j]!='\0')
            {
                if (try_tree[t][ch[j]-'A'].used==0)
                {
                    try_tree[t][ch[j]-'A'].used=1;
                    if (ch[j+1]=='\0') try_tree[t][ch[j]-'A'].last=1;
                    num++;
                    try_tree[t][ch[j]-'A'].next=num;
                    t=num;
                }
                else
                {
                    if (ch[j+1]=='\0') try_tree[t][ch[j]-'A'].last=1;
                    t=try_tree[t][ch[j]-'A'].next;
                }
                j++;
            }
        }
        scanf("%s",datach);
        printf("%d\n",p+1);
        search(0,0,ans,0,datach,0,try_tree);
    }
    return 0;
}
