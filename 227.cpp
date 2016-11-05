 #include<iostream>
 #include<string>
 #include<stack>
 using namespace std;
 int calculate(string s) {
        stack<char> mystackop;
        stack<int> mystacknum;
        int i = 0;
        int num1, num2;
        while(i < s.size()) {
            if (s[i] == ' ') {
                i ++; continue;
            }
            if (s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/') {
                mystackop.push(s[i]);
                i ++;
                continue;
            }
            num1 = 0;
            while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                num1 = num1 * 10 + s[i] - '0';
                i ++;
            }
            if (!mystackop.empty()) {
                if (mystackop.top() == '*') {
                    num1 = mystacknum.top() * num1;
                    mystacknum.pop();
                    mystackop.pop();
                } else if (mystackop.top() == '/') {
                    num1 = mystacknum.top() / num1;
                    mystacknum.pop();
                    mystackop.pop();
                }
            }
            mystacknum.push(num1);
        }
        int ans = 0;
        while(!mystackop.empty()) {
            num1 = mystacknum.top();
            if (mystackop.top() == '-') {
                ans -= num1;
            } else {
                ans += num1;
            }
            mystackop.pop();
            mystacknum.pop();
        }
        return mystacknum.top() + ans;
    }

int main() {
    cout<<calculate("1-1+1")<<endl;
}
