/*4Sum II

Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        unordered_map<int,int> mp;
        
        // Create a hash map and store all possible values of k+l
        for(int k : nums3)
            for(int l : nums4)
                mp[k + l]++;
        
        // From the values stored in the hash map, find -(i+j) for all possible values of i+j
        int count = 0;
        for(int i : nums1)
            for(int j : nums2)
                count += mp[-(i + j)];
        
        return count;
    }
};