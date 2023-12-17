#include <iostream>
#include <vector>
#include <algorithm>

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
        int gcdVal = 0;

        while (left <= right) {
            if (left % 2 == 1) {
                gcdVal = std::__gcd(gcdVal, tree[left]);
                left++;
            }
            if (right % 2 == 0) {
                gcdVal = std::__gcd(gcdVal, tree[right]);
                right--;
            }
            left /= 2;
            right /= 2;
        }

        return gcdVal;
    }

private:
    void build(const std::vector<int>& nums) {
        for (int i = 0; i < n; i++) {
            tree[n + i] = nums[i];
        }

        for (int i = n - 1; i > 0; i--) {
            tree[i] = std::__gcd(tree[2 * i], tree[2 * i + 1]);
        }
    }

    int n;
    std::vector<int> tree;
};

// Example Usage:
// int main() {
//     std::vector<int> nums = {2, 4, 6, 8, 10};
//     SegmentTree st(nums);
//     std::cout << st.query(1, 4) << std::endl;  // Output: 2 (GCD of 4, 6, 8, 10)
//     return 0;
// }
