#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
using namespace std;

struct node
{
    int a,b;
    node *next;
};
typedef node* nodes;
class polynomial
{
public:
     friend istream& operator >>(istream& ins, polynomial& the_object);
     friend ostream& operator <<(ostream& outs, const polynomial& the_object);
     polynomial();
     private:
     nodes head;
     int data;
};

polynomial::polynomial():head(NULL)
{
}
void readdata(istream& ins,int& data)
{
    ins>>data;
}
void readpo(istream& ins,nodes& head)
{
    string st;
    bool o=false;
    nodes p;
    p=new node;
    ins>>p->a;
    ins>>st;
    int j;
    for (int i=0; i<st.length(); i++)
    {
        if (st[i]=='x')
        {
            j=i; break;
        }
    }
    p->b=0; int t=1;
    for (int i=st.length()-1; i>j+1; i--)
    {
        p->b+=(st[i]-'0')*t;
        t*=10;
    }
    p->next=head;
    head=p;
    while (ins >> st)
    {
        if (st=="\n") break;
        if (st=="+")
        {
            o=false;
            continue;
        }
        if (st=="-")
        {
            o=true;
            continue;
        }
        int j=0;
        nodes p;
        p=new node;
        for (int i=0; i<st.length(); i++)
        {
            if (st[i]=='x')
            {
                j=i; break;
            }
        }
        if (j==0)
        {
            p->b=0;
            p->a=0; int t=1;
            for (int i=st.length()-1; i>=0; i--)
            {
                p->a+=(st[i]-'0')*t;
                t*=10;
            }
        }
        else
        {
            p->a=0; int t=1;
            for (int i=j-1; i>=0; i--)
            {
                p->a+=(st[i]-'0')*t;
                t*=10;
            }
            p->b=0; t=1;
            for (int i=st.length()-1; i>j+1; i--)
            {
                p->b+=(st[i]-'0')*t;
                t*=10;
            }
        }
        if (o) p->a=-p->a;
        p->next=head;
        head=p;
    }
}
void ccout(ostream& outs, nodes head , int data)
{
    int ans=0;
    int t;
    for (nodes p=head; p!=NULL; p=p->next)
    {
        t=1;
        for (int i=0; i<p->b; i++)
        t*=data;
        ans+=t*p->a;
    }
    outs << ans <<endl;
}
ostream& operator <<(ostream& outs, const polynomial& the_object)
{
    ccout(outs,the_object.head,the_object.data);
    return outs;
}
istream& operator >>(istream& ins, polynomial& the_object)
{
     readdata(ins,the_object.data);
     readpo(ins,the_object.head);
     return ins;
}

int main()
{
    polynomial poly;
    cin >> poly;
    cout << poly;
    return 0;
}
