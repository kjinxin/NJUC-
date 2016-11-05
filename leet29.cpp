#include<iostream>
#include<limits.h>
using namespace std;
int divide(int dividend, int divisor) {
        int count = 0, sign = 1;

        long long div = dividend, divor = divisor;
        if (div < 0) {
            div = -div; sign = -1;
        }
        if (divor < 0) {
            divor = -divor; sign *= -1;
        }
        while(div >= divor) {
            long long t = 1;
            while(t * divor <= div) {
                t <<= 1;
            }
            t >>= 1;
            div -= divor * t;
            count += t;
        }
        return count * sign;
    }
int main() {
    cout<<divide(-2147483648, 1)<<endl;
}
