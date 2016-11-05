#include<string>
#include<iostream>
using namespace std;
int myAtoi(string str) {
        int s = 0;
        while (str[s] == ' ' && s < str.size()) s ++;
        int sig = (str[s] == '-') ? -1 : 1;
        int result = 0;
        for (int i = (str[s] == '-' || str[s] == '+') ? s + 1 : s; i < str.size(); i ++) {
                if (str[i] - '0' >= 0 && str[i] - '0' < 10) {
                    int test = result * 10 + (str[i] - '0');
                    if ((test - (str[i] - '0'))/ 10 == result) {
                        result = result * 10 + (str[i] - '0');
                        }
                    else {
                        return (sig == -1) ? -2147483648 : 2147483647;
                    }
                } else return result * sig;
                if (result < 0) return (sig == -1) ? -2147483648 : 2147483647;
        }
        return result * sig;
}

int main() {
    cout<< myAtoi("2147483648") <<endl;

}
