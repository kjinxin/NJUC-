#include<iostream>

using namespace std;

int main()
{
    int n; // user numbers
    int *p_alloc = new int[n + 1](); // 各用户的资源分配比例
    int *hash = new int[n](); //标记哪些用户需要资源
    int sum = 0;
    while(cin >> user_comein >> user_comeout)
    {
        if (hash[user_comein] == user_comein)
        {
            hash[user_comein] = user_comein;
            sum += p_alloc[user_comein];
        }
}
    }
}
