#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int l, q;
    vector<string> vec;
    string str;
    int g[200][200];
    cin >> l >> q;
    for (int i = 0; i < l; i ++) {
        cin >> str;
        vec.push_back(str);
    }
    string str1;
    for (int i = 0; i < 200; i ++) {
        for (int j = 0; j < 200; j ++) {
            g[i][j] = 10000000;
        }
    }
    for (int i = 0; i < l; i ++) {
        str = vec[i];
        for (int j = 0; j < l; j ++) {
            str1 = vec[j];
            int num = 0;
            if (str.size() == str1.size()) {
                for (int k = 0; k < str.size(); k ++) {
                    if (str[k] != str1[k]) num ++;
                }
            } else break;
            if (num <= 1) g[i][j] = num;
        }
    }

    for (int k = 0; k < l; k ++) {
        for (int i = 0; i < l; i ++)
        for (int j = 0; j < l; j ++) {
            if (g[i][j] > g[i][k] + g[k][j]){
                g[i][j] = g[i][k] + g[k][j];
            }
        }
    }
    int st, tt;
    for (int i = 0; i < q; i ++) {
        cin >> str >> str1;
        for (int j = 0; j < l; j ++) {
            if (vec[j] == str) st = j;
            if (vec[j] == str1) tt = j;
        }
        if (g[st][tt] < 10000000) cout<<g[st][tt]<<endl;
        else cout<<-1<<endl;
    }
}
