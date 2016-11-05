#include<iostream>
#include<string>

using namespace std;
bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {

            while(!(s[l] >= 'a' && s[l] <='z' || s[l] >= 'A'
                && s[l] <= 'Z' || s[l] >= '0' && s[l] <= '9')) l ++;
            while(!(s[r] >= 'a' && s[r] <='z' || s[r] >= 'A'
                && s[r] <= 'Z' || s[r] >= '0' && s[r] <= '9')) r --;
            if (l >= r) break;
            if (s[l] >= '0' && s[l] <= '9' || s[r] >= '0' && s[r] <= '9') {
                    if (s[l] == s[r]) {
                        l ++; r --; continue;
                    } else return false;
            }
            if (s[l] == s[r] || s[l] - s[r] == 'a' - 'A'
                || s[l] - s[r] == 'A' - 'a') {
                 l ++; r --; continue;
            }
            else return false;

        }
        return true;
}

int main() {
    cout << isPalindrome("0P") <<endl;
}
