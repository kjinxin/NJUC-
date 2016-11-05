#include<iostream>
#include<string>
#include<vector>
using namespace std;
class NumArray {
public:
    struct Node{
        int sum;
        int l, r;
        int pos;
    };
    vector<Node*> segtree;
    vector<int> num;
    void buildtree(int l, int r, int pos, vector<int>& sum) {
        if (l > r) return;
        Node* node = new Node();
        node->sum = sum[r] - sum[l - 1];
        node->l = l;
        node->r = r;
        node->pos = pos;
        segtree[pos] = node;
        if (l == r) return;
        else {
            int mid = (l + r) / 2;
            buildtree(l, mid, 2 * pos + 1, sum);
            buildtree(mid + 1, r, 2 * pos + 2, sum);
        }
    }
    NumArray(vector<int> &nums) {
        vector<int> sum(nums.size() + 1, 0);
        num.resize(nums.size());
        segtree.resize(nums.size() * 3 + 2);
        for (int i = 0; i < nums.size(); i ++) {
            sum[i + 1] = sum[i] + nums[i];
            num[i] = nums[i];
        }
        buildtree(1, nums.size(), 0, sum);
    }

    void updatetree(int i, int val, int pos) {
        if (segtree[pos]->l == i && segtree[pos]->r == i) {
            segtree[pos]->sum = val;
            return;
        }
        segtree[pos]->sum = segtree[pos]->sum + val - num[i - 1];
        int mid = (segtree[pos]->l + segtree[pos]->r) / 2;
        if (mid >= i) {
            updatetree(i, val, 2 * pos + 1);
        } else {
            updatetree(i, val, 2 * pos + 2);
        }
    }
    void update(int i, int val) {
        updatetree(i + 1, val, 0);
        num[i] = val;
    }

    int sumTree(int i, int j, int pos) {
        if (i == segtree[pos]->l && j == segtree[pos]->r) {
            return segtree[pos]->sum;
        }
        int mid = (segtree[pos]->l + segtree[pos]->r) / 2;
        if (j <= mid) {
            return sumTree(i, j, segtree[pos]->pos * 2 + 1);
        }
        if (i > mid) {
            return sumTree(i, j, segtree[pos]->pos * 2 + 2);
        }
        return sumTree(i, mid, segtree[pos]->pos * 2 + 1) + sumTree(mid + 1, j, segtree[pos]->pos * 2 + 2);
    }
    int sumRange(int i, int j) {
        return sumTree(i + 1, j + 1, 0);
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);
    cout<<numArray.sumRange(0, 2)<<endl;
    numArray.update(1, 2);
    cout<<numArray.sumRange(0, 2)<<endl;
}
