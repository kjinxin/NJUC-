#include<iostream>
#include<fstream>
using namespace std;

struct node
{
    int key,c,p,l,r;
};


void left_rotate(node t[],int &root,int x)
{
    int y=t[x].r;
    t[x].r=t[y].l;
    if (t[y].l!=0)
        t[t[y].l].p=x;
    t[y].p=t[x].p;
    if (t[x].p==0)
        root=y;
    else
    if (t[t[x].p].l==x)
        t[t[x].p].l=y;
    else
        t[t[x].p].r=y;
    t[y].l=x;
    t[x].p=y;
}

void right_rotate(node t[],int &root,int x)
{
    int y=t[x].l;
    t[x].l=t[y].r;
    if (t[y].r!=0)
        t[t[y].r].p=x;
    t[y].p=t[x].p;
    if (t[x].p==0)
        root=y;
    else
    if (t[t[x].p].r==x)
        t[t[x].p].r=y;
    else
        t[t[x].p].l=y;
    t[y].r=x;
    t[x].p=y;
}
void rb_insert_fixup(node t[],int &root,int z)
{
    int y;
    while (t[t[z].p].c==0)
    {
        if (t[z].p==t[t[t[z].p].p].l)
        {
            y=t[t[t[z].p].p].r;
            if (t[y].c==0)
            {
                t[t[z].p].c=1;
                t[y].c=1;
                t[t[t[z].p].p].c=0;
                z=t[t[z].p].p;
            }
            else
            {
                if (z==t[t[z].p].r)
                {
                    z=t[z].p;
                    left_rotate(t,root,z);
                }
                t[t[z].p].c=1;
                t[t[t[z].p].p].c=0;
                right_rotate(t,root,t[t[z].p].p);
            }
        }
        else
        {
            y=t[t[t[z].p].p].l;
            if (t[y].c==0)
            {
                t[t[z].p].c=1;
                t[y].c=1;
                t[t[t[z].p].p].c=0;
                z=t[t[z].p].p;
            }
            else
            {
                if (z==t[t[z].p].l)
                {
                    z=t[z].p;
                    right_rotate(t,root,z);
                }
                t[t[z].p].c=1;
                t[t[t[z].p].p].c=0;
                left_rotate(t,root,t[t[z].p].p);
            }
        }
    }
    t[root].c=1;
}
void rb_insert(node t[],int &root,int z)
{
    int y=0,x=root;
    while(x!=0)
    {
        y=x;
        if (t[z].key<t[x].key)
            x=t[x].l;
        else x=t[x].r;
    }
    t[z].p=y;
    if (y==0)
        root=z;
    else
    if (t[z].key<t[y].key)
        t[y].l=z;
    else t[y].r=z;
    t[z].l=0; t[z].r=0; t[z].c=0;
    rb_insert_fixup(t,root,z);
}

void print(node t[],int x)
{
    if (x==0)
        return;
    cout<<t[x].key<<':';
    if (t[x].c==1) cout<<"black"<<endl; else cout<<"red"<<endl;
    print(t,t[x].l);
    print(t,t[x].r);
}
void search(node t[],int x,int num,int k)
{
    if (x==0||t[x].key==k)
    {
        cout<<num<<endl;
        return;
    }
    if (k>t[x].key)
    search(t,t[x].r,num+1,k);
    else
    search(t,t[x].l,num+1,k);
}
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        int root=0;
        node t[100000];
        t[0].c=1; t[0].key=0; t[0].l=0; t[0].p=0; t[0].r=0;
        for (int i=1; i<=m; i++)
        {
            cin>>t[i].key;
            rb_insert(t,root,i);
        }
        print(t,root);
        for (int i=1; i<=n; i++)
        {
            int k;
            cin>>k;
            search(t,root,0,k);
        }
    }
}

