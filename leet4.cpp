class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n % 2 == 0) {
            return (findKthValue(nums1, 0, nums2, 0, n / 2) + findKthValue(nums1, 0, nums2, 0, n / 2 + 1)) / 2;
        } else {
            return findKthValue(nums1, 0, nums2, 0, n / 2 + 1);
        }
    }

    double findKthValue(vector<int>& nums1, int s1, vector<int>& nums2, int s2, int k) {
        if (nums1.size() <= s1) return nums2[s2 + k - 1];
        if (nums2.size() <= s2) return nums1[s1 + k - 1];
        if (k == 1) return (nums1[s1] < nums2[s2] ? nums1[s1] : nums2[s2]);
        int p = k / 2, q = k - p;
        if (p + s1 > nums1.size()) {
            p = nums1.size() - s1;
            q = k - p;
        }
        else if (q + s2 > nums1.size()) {
            q = nums2.size() - s2;
            p = k - q;
        }
        if (nums1[s1 + p - 1] == nums2[s2 + q - 1]) return nums1[s1 + p - 1];
        else if (nums1[s1 + p - 1] < nums2[s2 + q - 1]) return findKthValue(nums1, s1 + p, nums2, s2, k - p);
        else return findKthValue(nums1, s1, nums2, s2 + q, k - q);
    }
};
