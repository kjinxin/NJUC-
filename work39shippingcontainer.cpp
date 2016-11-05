#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
class shcon
{
public:
    void set (int nid);
    int access ();
    virtual void getma ();
private:
    int id;
    string manifest;
};
void shcon::set (int nid)
{
    id=nid;
}
int shcon::access ()
{
    return id;
}
void shcon::getma ()
{
    cout << manifest << endl;
}

class mashc : public shcon
{
public:
    void setmaf (string new_manifest);
    virtual void getma ();
private:
    string manifest;
};
void mashc::setmaf (string new_manifest)
{
    manifest=new_manifest;
}
void mashc::getma ()
{
    cout << manifest << endl;
}

class rfsc : public shcon
{
public:
    void add (int apple, int pear);
    virtual void getma ();
private:
    string manifest;
};
void rfsc::add (int apple, int pear)
{
    stringstream ss;
    string temp_apple=" crates of apples. ";
    string temp_pear=" crates of pears.";
    ss << apple << temp_apple << pear << temp_pear;
    manifest=ss.str();
}
void rfsc::getma ()
{
    cout << manifest << endl;
}
int main ()
{
    char ty[500];
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> ty[i];
    cin.get();
    shcon *ptr[100];
    for (int i=0; i<n; i++)
    {
        if (ty[i]=='M')
        {
            string str;
            getline(cin,str);
            mashc *msc;
            msc=new mashc;
            msc->setmaf (str);
            ptr[i]=msc;
        }
        if (ty[i]=='R')
        {
            int apple,pear;
            cin >> apple >> pear;
            cin.get();
            rfsc *rsc;
            rsc=new rfsc;
            rsc->add (apple,pear);
            ptr[i]=rsc;
        }
    }
    for (int i=0; i<n; i++)
    ptr[i]->getma();
    return 0;
}
