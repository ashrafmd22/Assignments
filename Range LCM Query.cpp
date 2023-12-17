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
        int lcmVal = 1;

        while (left <= right) {
            if (left % 2 == 1) {
                lcmVal = lcm(lcmVal, tree[left]);
                left++;
            }
            if (right % 2 == 0) {
                lcmVal = lcm(lcmVal, tree[right]);
                right--;
            }
            left /= 2;
            right /= 2;
        }

        return lcmVal;
    }

private:
    int lcm(int a, int b) {
        return (a / std::__gcd(a, b)) * b;
    }

    void build(const std::vector<int>& nums) {
        for (int i = 0; i < n; i++) {
            tree[n + i] = nums[i];
        }

        for (int i = n - 1; i > 0; i--) {
            tree[i] = lcm(tree[2 * i], tree[2 * i + 1]);
        }
    }

    int n;
    std::vector<int> tree;
};

// Example Usage:
// int main() {
//     std::vector<int> nums = {2, 4, 6, 8, 10};
//     SegmentTree st(nums);
//     std::cout << st.query(1, 4) << std::endl;  // Output: 120 (LCM of 4, 6, 8, 10)
//     return 0;
// }
