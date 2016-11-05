#include<stdio.h>
#include<fstream>
using namespace std;

ifstream fin("1168_5.in");
ofstream fout("1168_5.out");
struct node {
    int value;
    int value2;
    int index;
};

node a[1000010];
int num = 0;
void mysort(node s[], int l, int r)
{
    int i, j;
    node x;
    if (l < r)
    {
        i = l;
        j = r;
        x = s[i];
        while (i < j)
        {
            while(i < j && (s[j].value > x.value || s[j].value == x.value && s[j].value2 < x.value2))
				j--; /* 从右向左找第一个小于x的数 */
            if(i < j)
				s[i++] = s[j];


            while(i < j && (s[i].value < x.value  || s[i].value == x.value && s[i].value2 > x.value2))
				i++; /* 从左向右找第一个大于x的数 */
            if(i < j)
				s[j--] = s[i];
        }
        s[i] = x;
        mysort(s, l, i-1); /* 递归调用 */
        mysort(s, i+1, r);
    }
}
int main()
{
    while(fin>>a[num].index>>a[num].value>>a[num].value2)
    {
        num ++;
    }
    mysort(a, 0, num - 1);
    for (int i = 0; i < num; i ++)
    {
        fout<<a[i].index<<" "<<a[i].value<<" "<<a[i].value2<<endl;
    }
    return 0;
}


