#include<iostream>
#include<string>

using namespace std;
int lengthOfLastWord(string s) {
        int len = 0, pos = 0;
        bool o = false;
        while(pos < s.size()) {
            if (s[pos] == ' ') {
                len = 0;
                o = true;
            } else {
                len ++;
            }
            cout<<len<<endl;
            pos ++;
        }
        if (o) return len;
        else return 0;
    }

int main() {
    cout<<lengthOfLastWord("  ")<<endl;
}
