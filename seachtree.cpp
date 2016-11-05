#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
string a[1000] = {};
int time = 1;
void insert_tree(string a[], string temp)
{
    int point = 0;
    while (a[point] != "")
    {
        if (temp < a[point])
            point = 2 * point + 1;
        else point = 2 * point + 2;
    }
    a[point] = temp;
}

void print_tree(string a[], int point)
{
    if (a[point] == "") return;
    cout<<a[point]<<" "<<time++<<endl;
    print_tree(a, point * 2 + 1);
    print_tree(a, point * 2 + 2);
}
int main()
{
    string temp;
    for (int i = 0; i < 16; i ++)
    {
        cin>>temp;
        insert_tree(a, temp);
    }

    print_tree(a, 0);
    return 0;
}
