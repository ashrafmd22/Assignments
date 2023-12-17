/*Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

 */

 class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) ans=max(ans,dp[i]);
        return ans;
    }
};