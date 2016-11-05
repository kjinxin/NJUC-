#include<iostream>

using namespace std;

int main()
{
    long long ans = 0, leftnum = 0;
    char ch;
    while (cin >> ch)
    {
        if (ch == '(') leftnum ++;
        if (ch == ')') ans += leftnum;
    }
    cout << ans << endl;
}
