#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
        if (nums.size() <= 0) return -1;
        int l = 0, r = nums.size() - 1, mid, n = nums.size() - 1;
        while(l < r) {
            mid = (r - l) / 2 + l;
            if (nums[mid] == target) return mid;
            if (nums[r] > nums[l]) {
                if (nums[mid] > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] >= nums[l]) {
                    if (nums[mid] < target) {
                       l = mid + 1;
                    } else {
                        if (nums[l] > target) {
                            l = mid + 1;
                        } else {
                            r = mid - 1;
                        }
                    }
                } else {
                    if (nums[mid] > target) {
                        r = mid - 1;
                    } else {
                        if (nums[r] < target) {
                            r = mid - 1;
                        } else {
                            l = mid + 1;
                        }
                    }
                }
            }
        }
        if (nums[l] == target) return l;
        else return -1;
    }
int main() {
    vector<int> vec = {3, 1};
    cout<<search(vec, 1)<<endl;
    return 0;
}
