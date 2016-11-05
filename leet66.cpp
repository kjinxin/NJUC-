#include<iostream>
#include<vector>
using namespace std;

 vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        digits[n] ++;
        while (digits[n] > 9) {
            cout<< n<<' ' << digits[n]<<endl;
            if (n == 0) {
                digits.push_back(0);
                for (int i = digits.size() - 1; i > 0; i --) {
                    digits[i] = digits[i - 1];
                }
                digits[0] = 0;
                n ++;
            }
            cout<<n<<endl;
            digits[n] = 0;
            digits[--n] ++;
        }
        return digits;
 }
int main() {
    vector<int> vec = {9};
    plusOne(vec);
}
