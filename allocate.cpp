#include<iostream>

using namespace std;

int main()
{
    int n; // user numbers
    int *p_alloc = new int[n + 1](); // ���û�����Դ�������
    int *hash = new int[n](); //�����Щ�û���Ҫ��Դ
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
