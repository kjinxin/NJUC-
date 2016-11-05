#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

 int getPos(int n, int pos, int count) {
        while(count - pos > 0) {
            n /= 10;
            count --;
        }
        return n % 10;
    }
    int findNthDigit(int n) {
        int num = 9, count = 1;
        while (n > num * count) {
            n -= num * count;
            cout<<n<<endl;
            cout<<num<<endl;
            if (2147483647 / 10 < num * count) break;
            num *= 10;
            count ++;
        }
        int temp = (n - 1 + count) / count + num / 9 - 1;
        int mod = (n - 1) % count;

        return getPos(temp, mod, count);
    }
int main() {
    cout<<findNthDigit(1000000000)<<endl;
}
