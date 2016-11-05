#include<iostream>
#include<string>

using namespace std;

int compareVersion(string version1, string version2) {
        string subversion1, subversion2;
        int v1_pos = 0, v2_pos = 0, v1_pos_n, v2_pos_n;
        while(1) {
            v1_pos_n = version1.find(".", v1_pos);
            v2_pos_n = version2.find(".", v2_pos);
            if (v1_pos_n == -1) {
                subversion1 = version1.substr(v1_pos, version1.size() - v1_pos);
            } else {
                subversion1 = version1.substr(v1_pos, v1_pos_n - v1_pos);
            }
            if (v2_pos_n == -1) {
                subversion2 = version2.substr(v2_pos, version2.size() - v2_pos);
            } else {
                subversion2 = version2.substr(v2_pos, v2_pos_n - v2_pos);
            }
            int t = 0;
            while(t < subversion1.size() - 1 && subversion1[t] == '0') t ++;
            subversion1 = subversion1.substr(t, subversion1.size() - t);
            t = 0;
            while(t < subversion2.size() - 1 && subversion2[t] == '0') t++;
            subversion2 = subversion2.substr(t, subversion2.size() - t);
            cout<<subversion1<<endl;
            cout<<subversion2<<endl;
            if (subversion1 > subversion2) return 1;
            else if (subversion1 < subversion2) return -1;
            else {
                if (v1_pos_n == -1 && v2_pos_n == -1) return 0;
                else if (v2_pos_n == -1) return 1;
                else if (v1_pos_n == -1) return -1;
                else {
                    v1_pos = v1_pos_n + 1;
                    v2_pos = v2_pos_n + 1;
                }
            }
        }
        return 0;
    }
int main() {
    cout<<compareVersion("1.2", "1.10")<<endl;
    cout<<("a" > "b") <<("b" > "a")<<endl;
    string st = "122333";
    cout<<st.find("1", 10)<<endl;
    return 0;
}
