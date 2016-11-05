#include<vector>
#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void rotate(vector<int>& nums, int k) {
        int temp, newtemp, pos = 0, len = nums.size();
        for (int i = 0; i < gcd(len, k); i ++) {
            pos = i;
            temp = nums[i];
            do {
                newtemp = nums[(pos + k) % len];
                nums[(pos + k) % len] = temp;
                temp = newtemp;
                pos = (pos + k) % len;
            }while (pos != i);
        }
}

int main() {
    vector<int> vec;
    for (int i = 1; i < 7; i ++) vec.push_back(i);
    rotate(vec, 2);
    for (int i = 0; i < 6; i ++) cout<<vec[i]<<endl;
    return 0;
}
