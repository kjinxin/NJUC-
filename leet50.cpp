#include<iostream>
#include<vector>
using namespace std;
 double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) {
            x = 1 / x;
            n = 0 - n;
        }
        vector<int> vec;
        while(n > 0) {
            cout<<n<<endl;
            vec.push_back(n & 1);
            n >>= 1;
        }
        double answer = 1.0;
        for (int i = vec.size() - 1; i >= 0; i --) {
            answer *= answer;
            if (vec[i] == 1) {
                answer *= x;
            }
        }
        return answer;
    }
int main() {
    cout<<myPow(8.88023, 3)<<endl;
}
