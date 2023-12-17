#include <iostream>
#include <vector>

class SegmentTree {
public:
    SegmentTree(const std::vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 0, n - 1, 1);
    }

    int query(int k) {
        return findKthZero(k, 0, n - 1, 1);
    }

private:
    void build(const std::vector<int>& nums, int left, int right, int index) {
        if (left == right) {
            tree[index] = (nums[left] == 0) ? 1 : 0;
            return;
        }

        int mid = left + (right - left) / 2;
        build(nums, left, mid, 2 * index);
        build(nums, mid + 1, right, 2 * index + 1);

        tree[index] = tree[2 * index] + tree[2 * index + 1];
    }

    int findKthZero(int k, int left, int right, int index) {
        if (left == right) {
            return left;
        }

        int mid = left + (right - left) / 2;

        if (k <= tree[2 * index]) {
            return findKthZero(k, left, mid, 2 * index);
        } else {
            return findKthZero(k - tree[2 * index], mid + 1, right, 2 * index + 1);
        }
    }

    int n;
    std::vector<int> tree;
};

// Example Usage:
// int main() {
//     std::vector<int> nums = {1, 0, 1, 0, 0, 1, 1, 0};
//     SegmentTree st(nums);
//     std::cout << st.query(3) << std::endl;  // Output: 5 (Index of the 3rd zero in the array)
//     return 0;
// }
