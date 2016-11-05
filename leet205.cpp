#include<iostream>
#include<vector>
using namespace std;

 bool isIsomorphic(string s, string t) {
        vector<int> svec(256, -1);
        vector<int> tvec(256, -1);
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i ++) {
            if (svec[s[i]] == -1 && tvec[t[i]] == -1) {
                svec[s[i]] = t[i];
                tvec[t[i]] = s[i];
            } else {
                if (svec[s[i]] == -1 || tvec[t[i]] == -1) {
                        return false;
                }
                else
                if (svec[s[i]] != t[i]) {
                    return false;
                }
            }
            cout<<svec[s[i]]<<endl;
        }
        return true;
    }
int main() {
    cout<< isIsomorphic("aa", "bb")<<endl;
}
