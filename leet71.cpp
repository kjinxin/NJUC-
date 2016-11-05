#include<iostream>
#include<string>
#include<stack>
using namespace std;

 string simplifyPath(string path) {
        stack<string> mystack;
        string str;
        int st = 1, ed = 0;
        while(ed != -1) {
            st = ed + 1;
            ed = path.find("/", st);
            if (ed == -1) break;
            str = path.substr(st, ed - st);

            if (str.size() == 0) continue;
            if (str == "."){
            } else if (str == "..") {
                if (!mystack.empty()) {
                    mystack.pop();
                }
            } else {
                mystack.push(str);
            }
        }
        if (st != path.size()) {
            str = path.substr(st, path.size() - st);
            if (str == "."){
            } else if (str == "..") {
                if (!mystack.empty()) {
                    mystack.pop();
                }
            } else {
                mystack.push(str);
            }
        }
        string result = "";
        while(!mystack.empty()) {
            result = "/" + mystack.top() + result;
            mystack.pop();
        }
        if (result == "") return "/";
        else return result;
    }
int main() {
    cout<<simplifyPath("/...")<<endl;
}
