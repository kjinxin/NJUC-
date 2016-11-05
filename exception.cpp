#include <iostream>
using namespace std;

int n;

int func(int e)
{
    if (++e == n)
        throw e;
    func(e);
}

int main()
{
    cin >> n;
    try
    {
        if (!n)
            throw 0;
        func(0);
    }
    catch (int &e)
    {
        cout << e << endl;
    }
    return 0;
}
