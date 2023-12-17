/*Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.*/
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int l=0,h=n-1;
        int m;
        int c=0;
        if(target<nums[0])#checking condition
        {
            c=1;
        }
       
        while(l<=h)
        {
            m=l+(h-l)/2;
            if(c==1)
            {
                if(nums[m]>target && nums[0]>nums[m])
                {
                    h=m-1;
                }
                else if(nums[m]>target && nums[0]<=nums[m])
                {
                    l=m+1;
                }
                else if(nums[m]==target)
                {
                    return m;
                }
                else
                {
                    l=m+1;
                }
            }
            else
            {
                if(nums[m]<target && nums[0]>nums[m])
                {
                    h=m-1;
                }
                else if(nums[m]<target && nums[0]<=nums[m])
                {
                   l=m+1; 
                }
                else if(nums[m]==target)
                {
                    return m; 
                }
                else
                {
                    h=m-1;
                }
            }
        }
        return -1;
    }
};