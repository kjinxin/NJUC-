#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
 double findKthValue(vector<int>& nums1, int s1, vector<int>& nums2, int s2, int k) {
        cout<<s1 << " " << s2 << " " << k<< endl;
        if (nums1.size() <= s1) return nums2[s2 + k - 1];
        if (nums2.size() <= s2) return nums1[s1 + k - 1];
        if (k == 1) return (nums1[s1] < nums2[s2] ? nums1[s1] : nums2[s2]);
        int p = k / 2, q = k - p;

        if (p + s1 > nums1.size()) {
            p = nums1.size() - s1;
            q = k - p;
        }
        else if (q + s2 > nums2.size()) {
            q = nums2.size() - s2;
            p = k - q;
        }
        cout<< p << " " << q << " " << endl;
        if (nums1[s1 + p - 1] == nums2[s2 + q - 1]) return nums1[s1 + p - 1];
        else if (nums1[s1 + p - 1] < nums2[s2 + q - 1]) return findKthValue(nums1, s1 + p, nums2, s2, k - p);
        else return findKthValue(nums1, s1, nums2, s2 + q, k - q);
    }
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n % 2 == 0) {
            return (findKthValue(nums1, 0, nums2, 0, n / 2) + findKthValue(nums1, 0, nums2, 0, n / 2 + 1)) / 2;
        } else {
            return findKthValue(nums1, 0, nums2, 0, n / 2 + 1);
        }
    }


int main() {
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums2.push_back(2);
    nums2.push_back(3);
    nums2.push_back(4);
    cout<<findMedianSortedArrays(nums1, nums2);
}
