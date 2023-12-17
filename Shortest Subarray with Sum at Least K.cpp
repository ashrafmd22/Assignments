/*Shortest Subarray with Sum at Least K
Hard

4110

112

Add to List

Share
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.*/
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int n = nums.size();
        long pref[n + 1];
        
        pref[0] = 0;
        for(int i = 1; i != n + 1; ++i)
            pref[i] = pref[i - 1] + nums[i - 1];
        
        deque<int> dq;
        int res = INT_MAX;
        
        dq.push_back(0);
        for(int i = 1; i != n + 1; ++i) {
            while(!dq.empty() && pref[dq.back()] >= pref[i])
                dq.pop_back();
            while(!dq.empty() && pref[i] - pref[dq.front()] >= k) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }
};