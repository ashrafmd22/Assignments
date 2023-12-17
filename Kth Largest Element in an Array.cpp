/* Kth Largest Element in an Array

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());

        int i = nums.size() - k;

        return nums[i];
    }
};