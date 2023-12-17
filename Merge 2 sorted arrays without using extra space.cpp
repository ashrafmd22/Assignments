/*Merge 2 sorted arrays without using extra space*/
#include <iostream>
#include <vector>

void mergeSortedArrays(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int i = m - 1; // Index of last element in nums1
    int j = n - 1; // Index of last element in nums2
    int k = m + n - 1; // Index of last position in merged array (nums1)

    // Merge elements from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // If there are remaining elements in nums2, copy them to nums1
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    
    int m = 3; // Number of elements in nums1
    int n = 3; // Number of elements in nums2

    mergeSortedArrays(nums1, m, nums2, n);

    // Print the merged array
    for (int num : nums1) {
        std::cout << num << " ";
    }

    return 0;
}
