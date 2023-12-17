#include <iostream>
#include <vector>
#include <climits>

class SegmentTree {
public:
    SegmentTree(const std::vector<int>& nums) {
        n = nums.size();
        tree.resize(2 * n, INT_MIN); // Initialize for max query, use INT_MAX for min query
        build(nums);
    }

    int query(int left, int right) {
        left += n;
        right += n;
        int maxVal = INT_MIN; // Initialize for max query, use INT_MAX for min query

        while (left <= right) {
            if (left % 2 == 1) {
                maxVal = std::max(maxVal, tree[left]);
                left++;
            }
            if (right % 2 == 0) {
                maxVal = std::max(maxVal, tree[right]);
                right--;
            }
            left /= 2;
            right /= 2;
        }

        return maxVal;
    }

private:
    void build(const std::vector<int>& nums) {
        for (int i = 0; i < n; i++) {
            tree[n + i] = nums[i];
        }

        for (int i = n - 1; i > 0; i--) {
            tree[i] = std::max(tree[2 * i], tree[2 * i + 1]); // Use std::min for min query
        }
    }

    int n;
    std::vector<int> tree;
};

// Example Usage:
// int main() {
//     std::vector<int> nums = {1, 3, 5, 7, 9, 11};
//     SegmentTree st(nums);
//     std::cout << st.query(1, 4) << std::endl;  // Output: 9 (max value between indices 1 and 4)
//     return 0;
// }
