#include<iostream>
#include<string>
using namespace std;

template <class variabletype>
class set
{
    public:
        void init();
        void add();
        void remove();
        int getcount();
        bool determine(variabletype value);
        variabletype* getpoint();
    private:
        int size,num;
        void expand();
        void narrow();
        variabletype* data;
};
template <class variabletype>
void set<variabletype>::init()
{
    size=1; num=0;
    data=new variabletype[size];
}
template <class variabletype>
void set<variabletype>::expand()
{
    size*=2;
    variabletype* temp=new variabletype[size];
    for (int i=0; i<num; i++)
    temp[i]=data[i];
    data=temp;
}
template <class variabletype>
bool set<variabletype>::determine(variabletype value)
{
    for (int i=0; i<num; i++)
    {
        if (data[i]==value)
            return true;
    }
    return false;
}
template <class variabletype>
void set<variabletype>::add()
{
    variabletype value;
    cin>>value;
    if (num==size)
    {
        expand();
    }
    if (!determine(value))
    {
        data[num]=value;
        num++;
    }
}
template <class variabletype>
void set<variabletype>::remove()
{
    variabletype value;
    cin>>value;
    if (determine(value))
    {
        int j;
        for (int i=0; i<num; i++)
        {
            if (data[i]==value)
            {
                j=i; break;
            }
        }
        for (int i=j+1; i<num; i++)
        data[i-1]=data[i];
        num--;
    }
}
template <class variabletype>
int set<variabletype>::getcount()
{
    return num;
}
template <class variabletype>
variabletype* set<variabletype>::getpoint()
{
    return data;
}

int main()
{
    set<string> int1;
    int1.init();
    int ch,num1;
    while (cin>>ch)
    {
        switch (ch)
        {
            case 1:     int1.add(); break;
            case 2:     int1.remove(); break;
            case 3:     num1=int1.getcount(); cout<<num1<<endl; break;
            case 4:     {string value;
                        cin>>value;
                        if (int1.determine(value)) cout<<"TRUE"; else cout<<"FALSE";
                        break;}
            case 5:     {
                        num1=int1.getcount();
                        cout<<num1<<endl;
                        string* temp=int1.getpoint();
                        int1.init();
                        for (int i=0; i<num1-1; i++)
                        cout<<temp[i]<<' ';
                        cout<<temp[num1-1]<<endl;
                        break;}
        }
    }
    /*for (int i=0; i<10; i++) int1.add();
    string value;
    cin>>value;
    cout<<int1.determine(value)<<endl;
    int1.remove();
    int num=int1.getcount();
    cout<<num<<endl;
    string* temp=int1.getpoint();
    int1.init();
    for (int i=0; i<num-1; i++)
    cout<<temp[i]<<' ';
    cout<<temp[num-1]<<endl;
    */
}
