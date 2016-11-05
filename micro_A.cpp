#include<iostream>
using namespace std;
int main()
{
    int x, y, z;
    cin>> x >> y >> z;
    int num1 = 0, num2 = 0, num3 = 0;
    int dif1 = 0, dif2 = 0, dif3 = 0;
    int total = 0;
    int ans = 0;
    char ch;
    while(cin >> ch)
    {
        total ++;
        if (total > ans) ans = total;
        if (ch == 'R') num1 ++;
        if (ch == 'B') num2 ++;
        if (ch == 'Y') num3 ++;
        if (num1 - num2 > 0) dif1 = num1 - num2;
        else dif1 = num2 - num1;
        if (num1 - num3 > 0) dif2 = num1 - num3;
        else dif2 = num3 - num1;
        if (num2 - num3 > 0) dif3 = num2 - num3;
        else dif3 = num3 - num2;
        if (dif1 == x && dif2 ==y && dif3 ==z) total = 0;
        if (dif1 == x && dif2 ==z && dif3 ==y) total = 0;
        if (dif1 == y && dif2 ==x && dif3 ==z) total = 0;
        if (dif1 == y && dif2 ==z && dif3 ==x) total = 0;
        if (dif1 == z && dif2 ==x && dif3 ==y) total = 0;
        if (dif1 == z && dif2 ==y && dif3 ==x) total = 0;
        if (total == 0) {
            num1 = 0; num2 = 0; num3 = 0;
        }
    }
    cout << ans <<endl;
    return 0;
}
