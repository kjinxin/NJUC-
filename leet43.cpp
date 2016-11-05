#include<iostream>
#include<string>
using namespace std;
void init(string& num, int& sign) {
        if (num[0] == '-') {
            sign *= -1; num.erase(0, 1);
        }
        if (num[0] == '+') {
            num.erase(0, 1);
        }
    }
    string multiply(string num1, string num2) {
        int sign = 1;
        init(num1, sign);
        init(num2, sign);
        string result(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; i --) {
            for (int j = num2.size() - 1; j >= 0; j --) {
                int t = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
                cout<<t<<endl;
                result[i + j + 1] = '0' + t % 10;
                cout<<result[i + j + 1]<<endl;
                result[i + j] += t / 10;
                cout<<result[i + j]<<endl;
                cout<<result<<endl;
            }
        }
        cout<<result<<endl;
        int t = result.find_first_not_of('0');
        if (t == -1) {
            result = "0";
        } else {
            result.erase(0, t);
        }
        if (sign == -1) return "-" + result;
        else return result;
    }
int main() {
    cout<<multiply("1", "1")<<endl;
}
