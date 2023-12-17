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
        int zeroCount = 0;

        while (left <= right) {
            if (left % 2 == 1) {
                zeroCount += (tree[left] == 0);
                left++;
            }
            if (right % 2 == 0) {
                zeroCount += (tree[right] == 0);
                right--;
            }
            left /= 2;
            right /= 2;
        }

        return zeroCount;
    }

private:
    void build(const std::vector<int>& nums) {
        for (int i = 0; i < n; i++) {
            tree[n + i] = (nums[i] == 0) ? 1 : 0;
        }

        for (int i = n - 1; i > 0; i--) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

    int n;
    std::vector<int> tree;
};

// Example Usage:
// int main() {
//     std::vector<int> nums = {0, 1, 0, 0, 1, 0, 1, 1, 0, 1};
//     SegmentTree st(nums);
//     std::cout << st.query(1, 6) << std::endl;  // Output: 3 (Number of zeroes between indices 1 and 6)
//     return 0;
// }
