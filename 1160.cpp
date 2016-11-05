#include<iostream>
using namespace std;
int data[1001][1001], f[1001][1001],n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < i + 1; j ++)
        {
            cin >> data[i][j];
            f[i][j] = -1;
        }
    }
    f[0][0] = data[0][0];
    for (int i = 1; i < n; i ++)
    {
        for (int j = 0; j < i + 1; j ++)
        {
            if (j - 1 >= 0) f[i][j] = f[i - 1][j - 1];
            else f[i][j] = f[i - 1][j];
            if (j < i && f[i][j] > f[i - 1][j]) f[i][j] = f[i - 1][j];
            f[i][j] += data[i][j];
        }
    }
    int min1 = 10000000;
    for (int i = 0; i < n; i ++)
        if (min1 > f[n - 1][i]) min1 = f[n - 1][i];
    cout << min1 <<endl;
}
