#include <iostream>
#include <vector>

class SegmentTree {
public:
    SegmentTree(const std::vector<int>& nums) {
        n = nums.size();
        tree.resize(2 * n);
        build(nums);
    }

    int query(int left, int right) {
        left += n;
        right += n;
        int xorVal = 0;

        while (left <= right) {
            if (left % 2 == 1) {
                xorVal ^= tree[left];
                left++;
            }
            if (right % 2 == 0) {
                xorVal ^= tree[right];
                right--;
            }
            left /= 2;
            right /= 2;
        }

        return xorVal;
    }

private:
    void build(const std::vector<int>& nums) {
        for (int i = 0; i < n; i++) {
            tree[n + i] = nums[i];
        }

        for (int i = n - 1; i > 0; i--) {
            tree[i] = tree[2 * i] ^ tree[2 * i + 1];
        }
    }

    int n;
    std::vector<int> tree;
};

// Example Usage:
// int main() {
//     std::vector<int> nums = {1, 2, 3, 4, 5};
//     SegmentTree st(nums);
//     std::cout << st.query(1, 4) << std::endl;  // Output: 7 (2 ^ 3 ^ 4 ^ 5)
//     return 0;
// }
