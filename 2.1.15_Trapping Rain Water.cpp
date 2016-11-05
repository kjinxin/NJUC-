#include<iostream>
using namespace std;

class Solution {
public:
    void init();
    void trap();
    void print();
private:
    int size;
    int * data;
    int sum;
};
int main()
{
    Solution A;
    A.init();
    A.trap();
    A.print();
    return 0;
}
void Solution::init() {
        cin >> size;
        data = new int[size]();
        for (int i = 0; i < size; i ++) {
            cin >>data[i];
        }
        sum = 0;
    }
void Solution::trap() {
        int *max_left = new int[size]();
        int *max_right = new int[size]();
        for (int i = 1; i < size; i++) {
            max_left[i] = max(max_left[i - 1], data[i - 1]);
            max_right[size - 1 - i] = max(max_right[size - i], data[size - i]);
        }
        for (int i = 0; i < size; i++) {
            int height = min(max_left[i], max_right[i]);
            if (height > data[i]) {
                sum += height - data[i];
            }
        }
        delete[] max_left;
        delete[] max_right;
}
void Solution::print() {
        cout << sum <<endl;
}
