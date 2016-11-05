#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

 int getWord(int pos, string str) {
        int end = str.find(" ", pos);
        if (end == -1) end = str.size();
        return end;
    }
    bool wordPattern(string pattern, string str) {
        int num = count(str.begin(), str.end(), ' ');
        if (pattern.size() != num + 1) return false;
        vector<int> hash(256, -1);
        int pos = 0;
        string st1, st2;
        for (int i = 0; i < pattern.size(); i ++) {
            int pos_temp = getWord(pos, str);
            st1 = str.substr(pos, pos_temp - pos);
            if (hash[pattern[i]] == -1) {
                int t = str.find(st1, 0);
                if (t == pos) {
                    hash[pattern[i]] = pos;
                } else return false;
            } else {
                int pos2 = getWord(hash[pattern[i]], str);
                st2 = str.substr(hash[pattern[i]], pos2 - hash[pattern[i]]);
                cout<<st1<<endl;
                cout<<st2<<endl;
                if (st1 != st2) return false;
            }
            pos = pos_temp + 1;
        }
        return true;
    }
int main() {
    cout<< wordPattern("abba", "dog cat cat fish");
}
