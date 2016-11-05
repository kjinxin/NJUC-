#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("1156_1.in");
ofstream fout("1156_5.out");
char stack1[1000003];

int judge(char c1, char c2)
{
    if (c1 == '(' && c2 == ')') return 1;
    if (c1 == '[' && c2 == ']') return 1;
    if (c1 == '{' && c2 == '}') return 1;
    return 0;
}
int main()
{
    int top = 0, num = 0;
    fin >> stack1[top]; top ++;
    while (fin >> stack1[top])
    {
        if (top > 0 && judge(stack1[top - 1], stack1[top]))
        {
            top --;
            num ++;
        }
        else top ++;
    }
    if (top == 0) cout << num <<endl;
    else cout << 0 << endl;
}
