#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
    int num;
    int small, large, temp;
    int hash[100000];
    int a[100000], num1;
    int ans[100000];
    string line;
    getline(cin, line);
    istringstream in( line );
    in >> num;
    for (int i = 0; i < num; i ++) {
            for (int j = 0; j < 10000; j ++) {
                hash[j] = 0;
                a[j] = 0;
                ans[j] = 0;
            }
        num1 = 0;
        getline( cin, line );
        istringstream in(line);
        while (in >> a[num1 ++]);
        while (a[num1 - 1] == 0) num1 --;
        small = a[0]; large = a[0];
        for (int j = 0; j < num1; j ++) {
            if (a[j] < small) small = a[j];
            if (a[j] > large) large = a[j];
        }
        for (int j = 0; j < large - small + 1; j ++) {
            hash[j] = 0;
        }
        for (int j = 0; j < num1; j ++) {
            hash[a[j] - small] = 1;
        }
        int num2 = 0;
        for (int j = 0; j < large - small + 1; j ++) {
            if (hash[j] == 0) {
                ans[num2] = j;
                num2 ++;
            }
        }
        if (num2 > 0) {
            cout << ans[0] + small;
            for (int j = 1; j < num2; j ++)
                cout <<' '<<ans[j] + small;
        }
        cout << endl;
    }
}
