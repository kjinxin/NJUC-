#include<iostream>
using namespace std;

int sumFactor(int n) {
        int result = 0;
        while(n > 0) {
            result += (n % 10) * (n % 10);
            n /= 10;
        }
        return result;
    }
    bool isHappy(int n) {
        int fast = n, slow = n;
        while(1) {
            fast = sumFactor(fast);
            fast = sumFactor(fast);
            slow = sumFactor(slow);
            cout<<fast<<endl;
            cout<<slow<<endl;
            if (fast == slow) {
                if (fast == 1) return true;
                else return false;
            }
        }

    }
int main() {
    cout<<isHappy(7)<<endl;
}
