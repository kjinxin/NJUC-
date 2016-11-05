 #include<iostream>
#include<vector>
 using namespace std;

 vector<int> majorityElementK(vector<int>& nums, int k) {
        vector<int> vec;
        if (k <= 1) return vec;
        int data[k - 1], count[k - 1];
        for (int i = 0; i < k - 1; i ++) {
            data[i] = 0; count[i] = 0;
        }
        for (int i = 0; i < nums.size(); i ++) {
            int j;
            for (j = 0; j < k - 1; j ++) {
                if (data[j] == nums[i]) {
                    count[j] ++; break;
                }
            }
            if (j == k - 1) {
                for (j = 0; j < k - 1; j ++) {
                    if (count[j] == 0) {
                        data[j] = nums[i]; count[j] = 1; break;
                    }
                }
                if (j == k - 1) {
                    for (j = 0; j < k - 1; j ++) count[j] --;
                }
            }
        }
        for (int i = 0; i < k - 1; i ++) {
            int c = 0;
            if (count[i] <= 0) continue;
            for (int j = 0; j < nums.size(); j ++) {
                if (data[i] == nums[j]) c ++;
            }
            if (c > nums.size() / k) vec.push_back(data[i]);
        }
        for (int i = 0; i < vec.size(); i ++) cout<<vec[i]<<endl;
        return vec;
    }
    vector<int> majorityElement(vector<int>& nums) {
        return majorityElementK(nums, 3);
    }

int main() {
    vector<int> vec;
    vec.push_back(1);
    majorityElement(vec);
}
